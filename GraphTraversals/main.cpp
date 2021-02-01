// Graph Traversals - displays DFS and BFS of a graph of 12 cities and their 
// respective connections (edges)
// user choses the starting city for traversal

#include <iostream>
#include "graph.h"
using namespace std;

// for pair (a, b) of two cities represented by their index in an associated string array
struct pairs {
    int a, b;
};

int main()
{
    string vertices[] = { "Seattle", "San Francisco", "Los Angeles", "Denver", "Kansas", 
                          "Chicago", "Boston", "New York", "Atlanta", "Miami", "Dallas", "Houston" };
    
    // array of pairs containing all edges for the graph
    pairs edges[] = {   {.a = 0, .b = 1}, {.a = 0, .b = 3}, {.a = 0, .b = 5}, 
                        {.a = 1, .b = 2}, {.a = 1, .b = 3}, 
                        {.a = 2, .b = 3}, {.a = 2, .b = 4}, {.a = 2, .b = 10}, 
                        {.a = 3, .b = 4}, {.a = 3, .b = 5}, 
                        {.a = 4, .b = 5}, {.a = 4, .b = 7}, {.a = 4, .b = 8}, {.a = 4, .b = 10}, 
                        {.a = 5, .b = 6}, {.a = 5, .b = 7}, 
                        {.a = 6, .b = 7}, 
                        {.a = 7, .b = 8}, 
                        {.a = 8, .b = 9}, {.a = 8, .b = 10}, {.a = 8, .b = 11}, 
                        {.a = 9, .b = 11}, 
                        {.a = 10, .b = 11}  };

    int startCity = -1;
    char again = 'Y';
    Graph g(12, vertices);

    // add edges to the graph
    for (int i = 0; i < sizeof(edges) / 8; i++)
        g.addEdge(edges[i].a, edges[i].b);
  
    // i/o loop
    while (again == 'Y' || again == 'y') {
        
        while (startCity < 0 || startCity > 11) {
            cout << "\nEnter starting city using number from 0-11: ";
            cin >> startCity;
            cin.clear();
            cin.ignore(80, '\n');
        }

        cout << "You entered city name: " << vertices[startCity] 
             << "\n\nStarting at " << vertices[startCity] 
             << ", 12 cities are searched in this Depth-First Search order:\n";
        g.depthFirst(startCity);

        cout << "\n\nStarting at " << vertices[startCity] 
             << ", 12 cities are searched in this Breadth-First Search order:\n";
        g.breadthFirst(startCity);

        startCity = -1;
        cout << "\n\nTry another city (Y/N) ";
        cin >> again;
        cin.clear();
        cin.ignore(80, '\n');
    }

    return 0;
}

/*pairs edges[] = {   {.a = 0, .b = 1}, {.a = 0, .b = 3}, {.a = 0, .b = 5}, {.a = 1, .b = 0}, 
                    {.a = 1, .b = 2}, {.a = 1, .b = 3}, {.a = 2, .b = 1}, {.a = 2, .b = 3}, 
                    {.a = 2, .b = 4}, {.a = 2, .b = 10}, {.a = 3, .b = 0}, {.a = 3, .b = 1}, 
                    {.a = 3, .b = 2}, {.a = 3, .b = 4}, {.a = 3, .b = 5}, {.a = 4, .b = 3}, 
                    {.a = 4, .b = 5}, {.a = 4, .b = 7}, {.a = 4, .b = 8}, {.a = 4, .b = 10}, 
                    {.a = 5, .b = 0}, {.a = 5, .b = 3}, {.a = 5, .b = 4}, {.a = 5, .b = 6}, 
                    {.a = 5, .b = 7}, {.a = 6, .b = 5}, {.a = 6, .b = 7}, {.a = 7, .b = 4}, 
                    {.a = 7, .b = 5}, {.a = 7, .b = 6}, {.a = 7, .b = 8}, {.a = 8, .b = 4}, 
                    {.a = 8, .b = 7}, {.a = 8, .b = 9}, {.a = 8, .b = 10}, {.a = 8, .b = 11}, 
                    {.a = 9, .b = 8}, {.a = 9, .b = 11}, {.a = 10, .b = 2}, {.a = 10, .b = 4},
                    {.a = 10, .b = 8}, {.a = 10, .b = 11}, {.a = 11, .b = 8}, {.a = 11, .b = 9}, 
                    {.a = 11, .b = 10}  };*/