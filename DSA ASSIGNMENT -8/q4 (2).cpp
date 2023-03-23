#include <iostream>
#include <vector>
using namespace std;

bool isCyclicUtil(int vertex, vector<int> adjList[], vector<bool>& visited, int parent) {
    visited[vertex] = true;
    for (int i = 0; i < adjList[vertex].size(); i++) {
        int child = adjList[vertex][i];
        if (!visited[child]) {
            if (isCyclicUtil(child, adjList, visited, vertex))
                return true;
        } else if (child != parent)
            return true;
    }
    return false;
}

bool isCyclic(vector<int> adjList[], int vertices) {
    vector<bool> visited(vertices, false);
    for (int i = 0; i < vertices; i++)
        if (!visited[i])
            if (isCyclicUtil(i, adjList, visited, -1))
                return true;
    return false;
}

int main() {
    int vertices = 5;
    vector<int> adjList[vertices];

    adjList[1].push_back(0);
    adjList[0].push_back(1);
    adjList[1].push_back(2);
    adjList[2].push_back(1);
    adjList[2].push_back(4);
    adjList[4].push_back(2);
    adjList[4].push_back(3);
    adjList[3].push_back(4);
    adjList[3].push_back(0);
    adjList[0].push_back(3);

    if (isCyclic(adjList, vertices))
        cout << "The graph contains a cycle";
    else
        cout << "The graph doesn't contain a cycle";

    return 0;
}