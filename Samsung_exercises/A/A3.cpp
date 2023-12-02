#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int count_parallel_edges(vector<vector<int>>& edges) {
    unordered_map<int, int> edgeCount;

  
    for (size_t i = 0; i < edges.size(); ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        int edgeID = min(u, v) * 10 + max(u, v);
        edgeCount[edgeID]++;
    }

  
    int parallelEdges = 0;
    for (const pair<int, int>& it : edgeCount) {
        if (it.second > 1) {
            parallelEdges += it.second - 1;
        }
    }

    return parallelEdges;
}

int main() {
    vector<vector<int>> graph = {{0, 1}, {0, 1}, {1, 0}, {2, 4}, {4,1}};

    cout << "So canh song song trong do thi la: " << count_parallel_edges(graph) << endl;

    return 0;
}

