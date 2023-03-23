#include <iostream>
#include <vector>
using namespace std;

void DFS(int vertex, vector<int> adjList[], vector<bool>& visited) {
    visited[vertex] = true;
    for (int i = 0; i < adjList[vertex].size(); i++) {
        int child = adjList[vertex][i];
        if (!visited[child])
            DFS(child, adjList, visited);
    }
}

bool isConnected(vector<int> adjList[], int vertices) {
    vector<bool> visited(vertices, false);
    int i;
    for (i = 0; i < vertices; i++)
        if (adjList[i].size() != 0)
            break;
    if (i == vertices)
        return true;
    DFS(i, adjList, visited);
    for (i = 0; i < vertices; i++)
        if (visited[i] == false && adjList[i].size() > 0)
            return false;
    return true;
}

int main() {
    int vertices = 5;
    vector<int> adjList[vertices];


    adjList[0].push_back(1);
    adjList[1].push_back(0);
    adjList[1].push_back(2);
    adjList[2].push_back(1);
    adjList[3].push_back(4);
    adjList[4].push_back(3);

    if (isConnected(adjList, vertices))
        cout << "The graph is connected";
    else
        cout << "The graph is not connected";

    return 0;
}