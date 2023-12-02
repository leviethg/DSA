#include <iostream>
#include <vector>
#include <stack>
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
    }

    bool hasHamiltonPath() {
        vector<bool> visited(V, false);
        stack<int> s;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                int countVisited = 0;
                s.push(i);

                while (!s.empty()) {
                    int u = s.top();
                    s.pop();

                    if (!visited[u]) {
                        visited[u] = true;
                        countVisited++;

                        for (int v : adjList[u]) {
                            if (!visited[v]) {
                                s.push(v);
                            }
                        }
                    }
                }

                if (countVisited != V) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    g.addEdge(0, 2);

    if (g.hasHamiltonPath()) {
        cout << "There exists a unique topological order.\n";
    } else {
        cout << "There does not exist a unique topological order.\n";
    }

    return 0;
}

