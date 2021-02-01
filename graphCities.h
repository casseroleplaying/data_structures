#pragma once
#include <iostream>
#include <list>
#include <string>
using namespace std;

struct node {
    string city;
    node* next;
};

class Graph {
public:
    Graph(int n);
    ~Graph();
    void addVertex(string s);
    void addEdge(string s1, string s2);
    void dfs(int v);
    //void dfs(string s);
    void bfs(string s);
    void reset();
    void printGraph() const;

    int size, currentSize = 0;
    node *head;
    bool *visited;
    bool* queued;
};

Graph::Graph(int n)
{
    size = n;
    head = new node[size];
    visited = new bool[size]();
    queued = new bool[size]();
}

Graph::~Graph()
{
    node* np;
    node* temp;

    for (int i = 0; i < size; i++) {
        np = head + i;
        while (np->next != nullptr) {
            temp = np;
            np = np->next;
            delete temp;
        }
    }

    delete[] head;
    delete[] visited;
    delete[] queued;
}

void Graph::addVertex(string s)
{
    head[currentSize].city = s;
    head[currentSize].next = nullptr;
    currentSize++;
}

void Graph::addEdge(string s1, string s2)
{
    // find city1 in head array
    int i = 0;
    while (s1 != head[i].city)
        ++i;

    // traverse the list until the end
    node *np = head + i;
    while (np->next != nullptr) {
        np = np->next;
    }

    // add city2 to city1's list
    np->next = new node;
    np->next->city = s2;
    np->next->next = nullptr;

    // find city2 in head array 
    i = 0;
    while (s2 != head[i].city)
        ++i;

    // traverse the list until the end
    np = head + i;
    while (np->next != nullptr) {
        np = np->next;
    }

    // add city1 to city2's list
    np->next = new node;
    np->next->city = s1;
    np->next->next = nullptr;
}

void Graph::dfs(int v)
{
    node* np = &head[v];
    

        if (!visited[v]) {
            cout << head[v].city << " ";
            visited[v] = true;
            int j = 0;
            while (head[v].next->city != head[j].city)
                j++;
            dfs(j);
        }
        else {
            int j = 0;
            while (head[v].next->next->city != head[j].city)
                j++;
            v = j;
        }

}

//void Graph::dfs(string s)
//{
//    // find s in head array
//    int i = 0, v = 0;
//    while (head[i].city != s)
//        i++;
//
//    // output the first city and mark as visited
//    cout << "\nStarting at " << head[i].city << ", " << currentSize
//        << " cities are searched in this Depth-First Search order:\n"
//        << head[i].city;
//    visited[i] = true;
//    v++;
//
//    // work through all vertices in depth first order
//    node* np = head + i;
//    node* nc = np;
//
//    bool set = false, end = false;
//
//
//
//        while (np->next != nullptr && v < 12) {
//            np = np->next;
//            set = false;
//
//            // find the index for the city in head array
//            int j = 0;
//            while (np->city != head[j].city)
//                j++;
//
//            // if not visited, output, mark as visited, move pointer to it's list
//            if (!visited[j]) {
//                nc = np;
//                np = &head[j];
//                cout << ", " << np->city;
//                visited[j] = true;
//                set = true;
//                v++;
//            }
//            if (np->next == nullptr && !set) {
//                // find the index for the city in head array
//                int j = 0;
//                while (nc->next->city != head[j].city && j < 12)
//                    j++;
//                np = &head[j];
//                cout << ", " << np->city;
//                visited[j] = true;
//                set = true;
//                v++;
//            }
//        }
//
//    cout << "\n";
//
//    // clear the visited array for subsequent traversals
//    reset();
//}

void Graph::bfs(string s)
{
    // get the starting list
    int i = 0, v = 1;
    while (head[i].city != s)
        i++;

    // print the first city, mark as visited and queued
    cout << "\nStarting at " << head[i].city << ", " << currentSize
         << " cities are searched in this Breadth-First Search order:\n"
         << head[i].city;
    visited[i] = true;
    queued[i] = true;

    // point to the starting list
    node* np = head + i;

    // simple queue for each list
    int front = 0, back = -1;
    string *queue = new string[size-1];

    // traverse until all vertices are visited
    while (v < currentSize) {

        // print the current list and mark cities as visited
        while (np->next != nullptr) {

            np = np->next;

            // find the index for visited array
            int j = 0;
            while (np->city != head[j].city)
                j++;

            // place cities from current list in queue
            if (!queued[j]) {
                back++;
                queue[back] = np->city;
                queued[j] = true;
            }

            // if not visited, print and mark as visited, increment v counter
            if (!visited[j]) {
                cout << ", " << np->city;
                visited[j] = true;
                v++;
            }
        }

        // pop the front of the queue
        string popped = queue[front];
        front++;

        // find the index for next list
        int j = 0;
        while (popped != head[j].city)
            j++;

        // move np to process this list on next iteration of loop
        np = head + j;
    }

    // clear the visited, queued arrays for subsequent traversals
    reset();

    cout << "\n";
}

// printGraph() - prints the adjacency list
void Graph::printGraph() const
{
    cout << "\nGraph Contents as Adjacency List\n";
    for (int i = 0; i < currentSize; i++) {
        node* np = &head[i];
        while (np != nullptr) {
            cout << np->city << " <-> ";
            np = np->next;
        }
        cout << "\\\n";
    }
}

// reset() - resets the bool arrays to false
void Graph::reset()
{
    for (int i = 0; i < size; i++) {
        visited[i] = false;
        queued[i] = false;
    }
}