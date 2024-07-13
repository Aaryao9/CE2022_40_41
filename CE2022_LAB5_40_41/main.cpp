#include <iostream>
#include <unordered_map>
#include <list>
#include <cstdlib>
#include "graph.h"
using namespace std;

void printAdjacencyList(const unordered_map<int, list<int>>& adj) {
    cout << "Adjacency List:\n";
    for (const auto& pair : adj) {
        cout << pair.first << " -> ";
        for (int vertex : pair.second) {
            cout << vertex << " ";
        }
        cout << endl;
    }
}

int main() {
    Graph graph(false);

    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(4, 5);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);

    printAdjacencyList(graph.getAdjList());

    cout << "Total number of vertices: " << graph.numVertices() << endl;
    cout << "Total number of edges: " << graph.numEdges() << endl;

    int vertex = 1;
    cout << "Degree of vertex " << vertex << ": " << graph.degree(vertex) << endl;
    cout << "In-degree of vertex " << vertex << ": " << graph.indegree(vertex) << endl;
    cout << "Out-degree of vertex " << vertex << ": " << graph.outdegree(vertex) << endl;

    cout << "Is vertex 2 a neighbor of vertex 1? " << (graph.neighbour(1, 2) ? "Yes" : "No") << endl;
    cout << "Is vertex 3 a neighbor of vertex 1? " << (graph.neighbour(1, 3) ? "Yes" : "No") << endl;

    graph.removeEdge(1, 2);
    cout << "Adjacency List after removing the edge between 1 and 2:\n";
    printAdjacencyList(graph.getAdjList());

    graph.removeVertex(3);
    cout << "Adjacency List after removing vertex 3:\n";
    printAdjacencyList(graph.getAdjList());

    return 0;
}
