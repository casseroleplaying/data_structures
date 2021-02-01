#include <iostream>
#include <string>
#include "graphCities.h"
using namespace std;

int main()
{
    int startCity = -1;
    char again = 'Y';
    Graph g(12);

    string v[] = { "Seattle", "San Francisco", "Los Angeles", "Denver",
                          "Kansas", "Chicago", "Boston", "New York", "Atlanta",
                          "Miami", "Dallas", "Houston" };

    for (int i = 0; i < 12; i++)
        g.addVertex(v[i]);

    g.addEdge(v[0], v[1]);
    g.addEdge(v[0], v[3]);
    g.addEdge(v[0], v[5]);
    g.addEdge(v[1], v[3]);
    g.addEdge(v[1], v[2]);
    g.addEdge(v[2], v[3]);
    g.addEdge(v[2], v[4]);
    g.addEdge(v[2], v[10]);
    g.addEdge(v[3], v[4]);
    g.addEdge(v[3], v[5]);
    g.addEdge(v[4], v[5]);
    g.addEdge(v[4], v[7]);
    g.addEdge(v[4], v[8]);
    g.addEdge(v[4], v[10]);
    g.addEdge(v[5], v[6]);
    g.addEdge(v[5], v[7]);
    g.addEdge(v[6], v[7]);
    g.addEdge(v[7], v[8]);
    g.addEdge(v[8], v[9]);
    g.addEdge(v[8], v[10]);
    g.addEdge(v[8], v[11]);
    g.addEdge(v[9], v[11]);
    g.addEdge(v[10], v[11]);

    while (again == 'Y' || again == 'y') {
        
        while (startCity < 0 || startCity > 11) {
            cout << "\nEnter starting city using number from 0-11: ";
            cin >> startCity;
        }

        g.dfs(startCity);
        g.reset();
        g.bfs(v[startCity]);

        startCity = -1;
        cout << "\nTry another city (Y/N) ";
        cin >> again;
    }

    g.printGraph();

    system("pause");
    return 0;
}