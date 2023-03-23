#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int vertex, vector<int> adjList[], vector<bool>& visited) {
    visited[vertex] = true;
    cout << vertex << " ";
    for (int i = 0; i < adjList[vertex].size(); i++) {
        int child = adjList[vertex][i];
        if (!visited[child])
            DFS(child, adjList, visited);
    }
}

void BFS(int vertex, vector<int> adjList[], vector<bool>& visited) {
    queue<int> q;
    q.push(vertex);
    visited[vertex] = true;
    while (!q.empty()) {
        int currVertex = q.front();
        cout << currVertex << " ";
        q.pop();
        for (int i = 0; i < adjList[currVertex].size(); i++) {
            int child = adjList[currVertex][i];
            if (!visited[child]) {
                q.push(child);
                visited[child] = true;
            }
        }
    }
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

    vector<bool> visited(vertices, false);

    cout << "DFS: ";
    for (int i = 0; i < vertices; i++)
        if (!visited[i])
            DFS(i, adjList, visited);

    fill(visited.begin(), visited.end(), false);
    cout << endl;

    cout << "BFS: ";
    for (int i = 0; i < vertices; i++)
        if (!visited[i])
            BFS(i, adjList, visited);

    return 0;
}