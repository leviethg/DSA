#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool findHamiltonianPath(int v, vector<bool>& visited, vector<int>& path) {
        visited[v] = true;
        path.push_back(v);

        if (path.size() == V) {
            return true;
        }

        for (int i : adjList[v]) {
            if (!visited[i] && findHamiltonianPath(i, visited, path)) {
                return true;
            }
        }

        visited[v] = false;
        path.pop_back();
        return false;
    }

    bool hasHamiltonCycle() {
        vector<bool> visited(V, false);
        vector<int> path;

        for (int i = 0; i < V; ++i) {
            path.clear();
            if (findHamiltonianPath(i, visited, path)) {
                if (adjList[path.back()].end() != find(adjList[path.back()].begin(), adjList[path.back()].end(), path.front())) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 0);

    cout << "Does the graph have a Hamiltonian cycle? \n";
    if (g.hasHamiltonCycle()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

