#include "graph.h"
#include <iostream>
#include "log.h"
#include<algorithm>
#define MAX_VALUE 65536
#define TAG "native@graph"

void Graph::addVertex(int id, vector<Vertex> &vertexs) {
	this->vertexes.insert(make_pair(id, vertexs));
}

vector<int> Graph::getShortestPath(int start, int finish) {
	map<int,int> distances;
	priority_queue<Vertex> nodes;
	map<int,Vertex> previous;
	vector<int> path;

	map<int, vector<Vertex> >::iterator it;
	map<int, int>::iterator dis_it;
	map<int, Vertex>::iterator pre_it;
	for(it = this->vertexes.begin(); it != this->vertexes.end(); ++it) {
		if (it->first == start) {
			distances.insert(make_pair(start, 0));
			nodes.push(Vertex(start, 0));
		} else {
			distances.insert(make_pair(it->first, MAX_VALUE));
			nodes.push(Vertex(it->first, MAX_VALUE));
		}
		
		previous.insert(make_pair(it->first, Vertex(-1, 0)));
	}
	
	while(!nodes.empty()) {
		Vertex smallest = nodes.top();
		nodes.pop();
		
		if (smallest.getId() == finish) {
			while((pre_it = previous.find(smallest.getId())) != previous.end() && pre_it->second.getId()!=-1) {
				LOG_INFO(TAG, "------------path:%d", pre_it->first);
				path.push_back(pre_it->first);
				smallest = pre_it->second;
			}
			
			if (!path.empty()) {
				path.push_back(start);
				 reverse(path.begin(),path.end()); 
			}
			
			return path;
		}
		
		dis_it = distances.find(smallest.getId());
		if (dis_it == distances.end()) {
			cout << "can not find distance for:" << smallest.getId() << endl;
			return path;
		}
		
		int distanceValue = dis_it->second;
		
		if (distanceValue == MAX_VALUE) {
			break;
		}
		
		it = this->vertexes.find(smallest.getId());
		if (it == vertexes.end()) {
			return path;
		}
		
		vector<Vertex> nearNodes = it->second;
		for(int i = 0; i<nearNodes.size(); i++) {
			int n_id = nearNodes[i].getId();
			int n_dis = nearNodes[i].getDistance();
			int alt = distanceValue + n_dis;
			
			dis_it = distances.find(n_id);
			if (dis_it == distances.end()) {
				cout << "----------a----"<<endl;
				return path;
			}
			
			int dd = dis_it->second;
			bool need_fill = false;
			if (alt < dd) {
				//map无法覆盖key，只能下标方式
				distances[n_id] = alt;
				previous[n_id] = smallest;
				vector<Vertex> tmp;
				need_fill = true;
			}
			
			vector<Vertex> tmp;
			while(!nodes.empty()) {
				Vertex v = nodes.top();
				nodes.pop();
				if (v.getId() == n_id && need_fill == true) {
					v.setDistance(alt);
				}
				tmp.push_back(v);
			}

			for (int k=0; k < tmp.size(); k++) {
				nodes.push(tmp[k]);
			}
		}
	}
	
	vector<int> v;
	//for(dis_it= distances.begin(); dis_it != distances.end(); dis_it++) {
	//	v.push_back(dis_it->first);
	//}
	return v;
}
