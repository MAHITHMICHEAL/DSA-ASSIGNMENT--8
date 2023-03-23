#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<int> adjList[], int vertices) {
    vector<int> color(vertices, -1);
    for (int i = 0; i < vertices; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adjList[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u])
                        return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int vertices = 4;
    vector<int> adjList[vertices];

    adjList[0].push_back(1);
    adjList[1].push_back(0);
    adjList[1].push_back(3);
    adjList[3].push_back(1);
    adjList[2].push_back(3);
    adjList[3].push_back(2);

    if (isBipartite(adjList, vertices))
        cout << "The graph is bipartite";
    else
        cout << "The graph is not bipartite";

    return 0;
}