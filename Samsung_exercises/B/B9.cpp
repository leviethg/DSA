#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isConnected(vector<vector<int>> &graph) {
  int n = graph.size();
  vector<bool> visited(n, false);
  int count = 0;
  stack<int> st;
  st.push(0);

  while (!st.empty()) {
    int u = st.top();
    st.pop();
    if (!visited[u]) {
      visited[u] = true;
      count++;
      for (int v : graph[u]) {
        if (!visited[v]) {
          st.push(v);
        }
      }
    }
  }

  return count == n;
}

bool hasEulerCycle(vector<vector<int>> &graph) {
  int n = graph.size();
  vector<int> inDegree(n, 0);
  vector<int> outDegree(n, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (graph[i][j] > 0) {
        outDegree[i]++;
        inDegree[j]++;
      }
    }
  }

  if (!isConnected(graph)) {
    return false;
  }

  for (int i = 0; i < n; i++) {
    if (inDegree[i] != outDegree[i]) {
      return false;
    }
  }

  return true;
}

