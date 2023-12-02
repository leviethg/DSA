#include <iostream>
#include <vector>
using namespace std;

void DFS(int u, vector<vector<int>>& G, vector<bool>& visited) {
    visited[u] = true;
    for (int v : G[u]) {
        if (!visited[v]) {
            DFS(v, G, visited);
        }
    }
}

bool is_edge_connected(vector<vector<int>>& G) {
    int n = G.size();
    bool result = true;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (G[i][j] > 0) {
                int temp = G[i][j];
                G[i][j] = 0;
                G[j][i] = 0;

                vector<bool> visited(n, false);
                DFS(i, G, visited);

                for (int k = 0; k < n; ++k) {
                    if (!visited[k]) {
                        result = false;
                        break;
                    }
                }

                G[i][j] = temp;
                G[j][i] = temp;

                if (!result) {
                    break;
                }
            }
        }
        if (!result) {
            break;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> graph = {{0, 1, 0, 0, 1}, 
                                 {1, 1, 1, 0, 1}, 
                                 {0, 1, 1, 1, 0}, 
                                 {1, 0, 1, 0, 1}, 
                                 {0, 1, 0, 1, 1}};

    cout << "Do thi co lien thong canh hay khong? \n" << (is_edge_connected(graph) ? "Co" : "Khong") << endl;
    return 0;
}

