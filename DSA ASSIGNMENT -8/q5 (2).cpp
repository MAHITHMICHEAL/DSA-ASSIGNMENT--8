#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologicalSort(vector<int> adjList[], int vertices) {
    vector<int> inDegree(vertices, 0);
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < adjList[i].size(); j++)
            inDegree[adjList[i][j]]++;
    queue<int> q;
    for (int i = 0; i < vertices; i++)
        if (inDegree[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (int i = 0; i < adjList[u].size(); i++)
            if (--inDegree[adjList[u][i]] == 0)
                q.push(adjList[u][i]);
    }
}

int main() {
    int vertices = 6;
    vector<int> adjList[vertices];

    adjList[5].push_back(2);
    adjList[5].push_back(0);
    adjList[4].push_back(0);
    adjList[4].push_back(1);
    adjList[2].push_back(3);
    adjList[3].push_back(1);

    cout << "Topological Sort: ";
    topologicalSort(adjList, vertices);

    return 0;
}