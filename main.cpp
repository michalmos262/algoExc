#include "graph.h"


int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add some edges
    g.AddEdge(1, 2);
    g.AddEdge(1, 5);
    g.AddEdge(1, 3);
    g.AddEdge(2, 4);
    g.AddEdge(2, 5);
    g.AddEdge(3, 4);
    g.AddEdge(4, 5);

    // Print the graph
    g.printGraph();

    // Check adjacency
    cout << "Is 1 adjacent to 2? " << (g.IsAdjacent(1, 2) ? "Yes" : "No") << endl;
    cout << "Is 2 adjacent to 1? " << (g.IsAdjacent(2, 1) ? "Yes" : "No") << endl;

    // Get adjacency list of vertex 1
    try {
        const auto& adjList = g.GetAdjList(1);
        cout << "Adjacency list of vertex 1:";
        for (const int& adj : adjList) {
            cout << " " << adj;
        }
        cout << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }

    // Remove an edge
    g.RemoveEdge(1, 5);
    cout << "After removing edge between 1 and 5:" << endl;
    g.printGraph();

    // Print the number of vertices and edges
    cout << "Number of vertices: " << g.getNumOfVertices() << endl;
    cout << "Number of edges: " << g.getNumOfEdges() << endl;
}