#include "graph.h"
#include <iostream>
#include <list>
using namespace std;

// Graph() - allocates an adjacency list and string array of size v
//           populates the string array with the contents of s
Graph::Graph(int n, string *s) 
{ 
    numVertices = n;
    visited = new bool[numVertices]();
    adjacencyList = new list<int>[numVertices];
    vertices = new string[numVertices];

    for (int i = 0; i < numVertices; i++)
        vertices[i] = s[i];
} 

// addEdge() - adds an edge between vertices v1 and v2
void Graph::addEdge(int v1, int v2) 
{ 
    adjacencyList[v1].push_back(v2);
    // for a directed graph, comment out the below statement:
    adjacencyList[v2].push_back(v1);
}

// resetVisited() - resets the bool array for traversals
void Graph::resetVisited()
{
    for(int i = 0; i < numVertices; i++) 
        visited[i] = false;
}

// dfHelper() - recursive helper function to print the graph 
//              via depth-first traversal
void Graph::dfHelper(int n) 
{ 
    // mark and output vertex 
    visited[n] = true; 
    cout << vertices[n] << ", "; 
  
    // recur for adjacent vertices 
    list<int>::iterator it; 
    for (it = adjacencyList[n].begin(); it != adjacencyList[n].end(); ++it) 
        if (!visited[*it]) 
            dfHelper(*it); 
} 
  
// depthFirst() - calls recursive function to perform depth-first traversal
void Graph::depthFirst(int n) 
{ 
    // assume the worst and reset the visited array (why helper is needed)
    resetVisited();
    // call recursive function to perform traversal and output 
    dfHelper(n); 
} 

// breadtFirst() - performs breadt-first traversal of the graph
//               - outputs element of the associated string array
void Graph::breadthFirst(int n) 
{ 
    // assume the worst and reset the visited array
    resetVisited();

    // iterator for adjacent vertices
    list<int>::iterator it; 
  
    // queue for breadth-first output 
    list<int> queue; 
  
    // mark and output vertex 
    visited[n] = true; 
    queue.push_back(n); 
  
    while(!queue.empty()) { 
        // output vertex and dequeue
        n = queue.front(); 
        cout << vertices[n] << ", "; 
        queue.pop_front(); 
  
        // mark, enqueue unvisited adjacent vertices
        for (it = adjacencyList[n].begin(); it != adjacencyList[n].end(); ++it) { 
            if (!visited[*it]) { 
                visited[*it] = true; 
                queue.push_back(*it); 
            } 
        } 
    } 
}