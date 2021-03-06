#include "park_tt_com_parking_model_Graph.h"
#include "log.h"
#include "graph.h"
#include "util.h"

using namespace std;

#define TAG "native@graph"

JNIEXPORT void JNICALL Java_park_tt_com_parking_model_Graph_init
  (JNIEnv *env, jobject jobj) {
  wxLogEnable(1);
  Graph* a = new Graph();
  setJavaIntField(env, jobj, "ref", (int)a);
}

JNIEXPORT void JNICALL Java_park_tt_com_parking_model_Graph_destory
  (JNIEnv *env, jobject jobj) {
  	   Graph* ref = (Graph*)getJavaIntField(env, jobj, "ref");
  	   delete ref;
}

  

/*
 * Class:     park_tt_com_parking_model_Graph
 * Method:    addVertex
 * Signature: (ILjava/util/List;)V
 */
JNIEXPORT void JNICALL Java_park_tt_com_parking_model_Graph_addVertex
  (JNIEnv *env, jobject jobj, jint node, jobject nearnodes) {
  LOG_INFO(TAG, "start ivoke addVertex-----------");
  jclass class_arraylist = env->FindClass("java/util/List");

  jmethodID method_arraylist_get = env->GetMethodID(class_arraylist, "get", "(I)Ljava/lang/Object;");
  jmethodID method_arraylist_size = env->GetMethodID(class_arraylist, "size", "()I");

  jint size = env->CallIntMethod(nearnodes, method_arraylist_size);
  vector<Vertex> v;
  for(int i=0; i<size; i++){
    jobject item = env->CallObjectMethod(nearnodes, method_arraylist_get, (jint)i);
    Vertex vertex;
    int id = getJavaIntField(env, item, "id");
    vertex.setId(id);
    int distance = getJavaIntField(env, item, "distance");
    vertex.setDistance(distance);
    v.push_back(vertex);
    env->DeleteLocalRef(item);
  }

  Graph* ref = (Graph*)getJavaIntField(env, jobj, "ref");
  ref->addVertex(node, v);
}

/*
 * Class:     park_tt_com_parking_model_Graph
 * Method:    getShortestPath
 * Signature: ()Ljava/util/List;
 */
JNIEXPORT jobject JNICALL Java_park_tt_com_parking_model_Graph_getShortestPath
  (JNIEnv *env, jobject jobj, jint start, jint finish) {
  LOG_INFO(TAG, "start ivoke getShortestPath-----------");
  Graph* ref = (Graph*)getJavaIntField(env, jobj, "ref");
  vector<int> result = ref->getShortestPath(start, finish);
  
  jclass class_arraylist = env->FindClass("java/util/ArrayList");
  jclass class_msgitem = env->FindClass("java/lang/Integer");
  jmethodID method_arraylist_add = env->GetMethodID(class_arraylist, "add", "(Ljava/lang/Object;)Z");
  jmethodID mtd_arrayList_init = env->GetMethodID(class_arraylist, "<init>", "(I)V");
  jmethodID mtd_msgitem_init = env->GetMethodID(class_msgitem, "<init>", "(I)V");

  int size = result.size();
  jobject msglist = env->NewObject(class_arraylist, mtd_arrayList_init, size);
  for(int i=0; i<size;i++) {
      LOG_INFO(TAG, "path:-----------%d",result[i]);
      jobject jitem = env->NewObject(class_msgitem, mtd_msgitem_init, result[i]);
      env->CallBooleanMethod(msglist, method_arraylist_add, jitem);
      env->DeleteLocalRef(jitem);
  }
  
  return msglist;
}
