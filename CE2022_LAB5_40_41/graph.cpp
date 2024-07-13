#include <iostream>
#include "graph.h"

Graph::Graph(bool isDirected) : directed(isDirected) {}

bool Graph::isEmpty() const {
    return adjList.empty();
}

bool Graph::isDirected() const {
    return directed;
}

void Graph::addVertex(int newVertex) {
    adjList[newVertex];
}

void Graph::addEdge(int vertex1, int vertex2) {
    adjList[vertex1].push_back(vertex2);
    if (!directed) {
        adjList[vertex2].push_back(vertex1);
    }
}

void Graph::removeVertex(int vertexToRemove) {
    adjList.erase(vertexToRemove);
    for (auto& pair : adjList) {
        pair.second.remove(vertexToRemove);
    }
}

void Graph::removeEdge(int vertex1, int vertex2) {
    adjList[vertex1].remove(vertex2);
    if (!directed) {
        adjList[vertex2].remove(vertex1);
    }
}

int Graph::numVertices() const {
    return adjList.size();
}

int Graph::numEdges() const {
    int count = 0;
    for (const auto& pair : adjList) {
        count += pair.second.size();
    }
    if (!directed) {
        count /= 2;
    }
    return count;
}

int Graph::indegree(int vertex) const {
    int count = 0;
    for (const auto& pair : adjList) {
        for (const auto& v : pair.second) {
            if (v == vertex) {
                count++;
            }
        }
    }
    return count;
}

int Graph::outdegree(int vertex) const {
    return adjList.at(vertex).size();
}

int Graph::degree(int vertex) const {
    return outdegree(vertex) + (directed ? indegree(vertex) : 0);
}

std::list<int> Graph::neighbours(int vertex) const {
    return adjList.at(vertex);
}

bool Graph::neighbour(int vertex1, int vertex2) const {
    for (const auto& v : adjList.at(vertex1)) {
        if (v == vertex2) {
            return true;
        }
    }
    return false;
}

std::unordered_map<int, std::list<int>> Graph::getAdjList() const {
    return adjList;
}