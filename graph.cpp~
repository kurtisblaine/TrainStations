#include "graph.h"

GRAPH::GRAPH()
{
	nodeCount = 0;
}

GRAPH::GRAPH(int nodes)
{
	
	nodeCount = (nodes + 1);
	array = new adjList[nodeCount];

	for(int i = 1; i < nodeCount; i++){
		array[i].head = NULL;
	}

	
}


void GRAPH::setEdge(int source, int destination, int weight, string name[], int departTime, int arriveTime)
{			
	if(source != 0 && destination != 0 && weight != 0 && departTime != 0 && arriveTime != 0){

		listNode *node = new listNode;
		node->val = destination;
		node->weight = weight;
		node->name = name[destination];
		node->depart = departTime;
		node->arrive = arriveTime;
		node->next = NULL;
	
		node->next = array[source].head;
		array[source].head = node;		
	}

	else{	
		return;
	}
}

void GRAPH::printGraph()
{	
				cout<<"Train Itinerary: "<<endl;
				cout<<"--------------------------------\n";
				cout<<"ID   ";
				cout << "Destination\n";
				for(int j = 1; j < nodeCount; j++){
					listNode* temp = array[j].head;
					cout<<j<<" | ";
					while(temp != NULL){
							cout<< temp->name << " ";
							temp = temp->next;
					}
					
					cout<<endl;
				}
	
}

bool GRAPH::isAdjacent(int source, int destination){
					listNode* temp = array[source].head;
					while(temp != NULL){
							if(temp->val == destination){
								return true;
							}
							temp = temp->next;
					}
			return false;
}

void GRAPH::printGraphParameter(int user){
				listNode* temp = array[user].head;
				cout << "Train " << user << "'s Itinerary \n";
				cout << "------------------------------\n";
					while(temp != NULL){
						cout<<"Departure to " << temp->name;
						cout<<" at " << temp->depart;
						cout<<", arriving at " << temp->arrive << endl;
						temp = temp -> next;
					
					}
				cout <<endl;

}


	
bool GRAPH::isEmpty(vector<bool> vertex){
	for (int i = 0; i < vertex.size(); i++){
		if (vertex[i] == false){
			return false;
		}
	return true;
	}
}

void GRAPH::dijkstra(int source, int destination)
{	
	//list for visited/unvisited
	vector<bool> vertex;
	int distances[nodeCount];
	int minNode;
	int minDistance;
	int parent[nodeCount];

	for(int i =0;i<nodeCount;i++){
		distances[i] = INT_MAX;
		vertex.push_back(false);
		parent[i] = 0;
	}
	
	distances[source] = 0;

	while(!isEmpty(vertex)){
		minNode = INT_MAX;
		minDistance = INT_MAX;
		
		for(int vert = 0; vert < nodeCount; vert++){
			if(vertex[vert] == false && distances[vert] <= minDistance){
				minDistance = distances[vert];
				minNode = vert;
			}
		}
	
	
		vertex[minNode] = true;
		listNode* temp = array[minNode].head;
	
		for (int vert = 0; vert < nodeCount; vert++){

			while(temp != NULL){

				int u = minNode;
				int v = temp->val;
				int w = temp->weight;
				
				if(distances[u] != INT_MAX && distances[v] > distances[u] + w ){
					distances[v] = distances[u] + w;
					parent[v] = u;
				}
				
			temp = temp->next;
			}
	
		}
	
	}
	
	if(distances[destination]<60){
		cout << distances[destination] << " minutes." << endl;
	}
	else{
		cout << (distances[destination] - distances[destination]%60)/60<<" hours and "<< distances[destination]%60<<" minutes ";
	}
		

}

bool GRAPH::isReachable(int source, int destination){
	if(source == destination){
		return true;
	}
	

	//list for visited/unvisited
	bool *Tracked = new bool[nodeCount];
	for(int i = 0; i < nodeCount; i++){
		Tracked[i] = false;
	}

	//stack for push and pop
	stack<int> stack;
	stack.push(source);

	while(!stack.empty()){
		int top = stack.top();
		Tracked[top] = true;
		stack.pop();

		listNode* tmp = array[top].head;
		while(tmp != NULL){
			if(!Tracked[tmp->val]){
				stack.push(tmp->val);
				Tracked[tmp->val] = true;
			}

		tmp = tmp->next;

		}
	}
	
	return Tracked[destination];
}




