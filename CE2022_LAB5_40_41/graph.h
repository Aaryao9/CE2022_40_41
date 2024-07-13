#include <unordered_map>
#include <list>

class Graph {
private:
    std::unordered_map<int, std::list<int>> adjList;
    bool directed;
public:
    Graph(bool isDirected = false);

    bool isEmpty() const;
    bool isDirected() const;
    void addVertex(int newVertex);
    void addEdge(int vertex1, int vertex2);
    void removeVertex(int vertexToRemove);
    void removeEdge(int vertex1, int vertex2);
    int numVertices() const;
    int numEdges() const;
    int indegree(int vertex) const;
    int outdegree(int vertex) const;
    int degree(int vertex) const;
    std::list<int> neighbours(int vertex) const;
    bool neighbour(int vertex1, int vertex2) const;
    std::unordered_map<int, std::list<int>> getAdjList() const;

};
