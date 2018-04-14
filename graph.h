#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include <cstddef>
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
#include <climits>
#include <vector>
#include <functional>
#include <fstream>
#include <list>

using namespace std;

	struct adjList{
		
		struct listNode *head;
	};	

	struct listNode{
		int val;
		int weight;
		string name;
		int depart;
		int arrive;
		listNode* next;
	};


class GRAPH{
public:
	GRAPH();
	GRAPH(int);
	void setEdge(int, int, int, string[], int, int);
	void printGraph();
	// Use dijkstra's to find the shortest distance from a given node
	void dijkstra(int, int);
	bool isReachable(int, int);
	bool isEmpty(vector<bool>);
	void printGraphParameter(int);
	bool isAdjacent(int,int);

private:
	int *distances;
	int minNode, minDistance, departCin, arriveCin;
	int *parent;
	int u, v, w;
	adjList* array;
	listNode* temp;
	int nodeCount;
};


#endif
