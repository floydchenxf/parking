#ifndef GRAPH_H_
#define GRAPH_H_
#include <map>
#include <vector>
#include <queue>
#include "vertex.h"
#include <tr1/memory>

using namespace std;
class Graph {
	private:
		map<int, vector<Vertex> > vertexes;
	public:
		void addVertex(int id, std::vector<Vertex> &vertexs);
		vector<int> getShortestPath(int start, int finish);
};

typedef std::tr1::shared_ptr<Graph> GraphPtr;

#endif