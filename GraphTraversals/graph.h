#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <string>
using namespace std;

// Graph class for vertices of string type

class Graph {
private: 
    int numVertices;
    bool *visited;
    string *vertices;
    list<int> *adjacencyList; 
public:
    Graph(int n, string *s); 
    void addEdge(int v1, int v2); 
    void breadthFirst(int n);  
    void depthFirst(int n);
    void dfHelper(int n); 
    void resetVisited(); 
}; 

#endif