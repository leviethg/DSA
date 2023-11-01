#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortest_path(const vector<vector<int>>& graph, int start, int end) {
    vector<bool> visited(graph.size(), false);
    queue<pair<int, int>> q; // Hang doi luu tru cac node va khoang cach giua chung
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (node == end) {
            return dist; // Da tim duoc duong di ngan nhat
        }

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push({neighbor, dist + 1});
                visited[neighbor] = true;
            }
        }
    }

    return -1; // Khong co duong di tu X toi Y
}

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x - 1].push_back(y - 1);
    }

    int result = shortest_path(graph, X - 1, Y - 1);

    if (result == -1) {
        cout << "Khong co duong di tu X toi Y" << endl;
    } else {
        cout << result << " canh la duong di ngan nhat tu X toi Y" << endl;
    }

    return 0;
}

