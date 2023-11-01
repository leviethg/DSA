#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}

int count_connected_components(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
        int x = edge.first - 1;
        int y = edge.second - 1;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<bool> visited(n, false);
    int connected_components = 0;

    for (int node = 0; node < n; ++node) {
        if (!visited[node]) {
            dfs(graph, visited, node);
            connected_components++;
        }
    }

    return connected_components;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    int result = count_connected_components(n, edges);
    cout << result << endl;

    return 0;
}

