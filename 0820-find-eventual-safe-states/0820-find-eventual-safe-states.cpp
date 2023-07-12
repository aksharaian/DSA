class Solution {
public:
  vector<int> topo;
  int n;
  void findTopo(vector<vector<int>> &graph, int node, vector<int> &visited) {
    visited[node] = 1;

    for (int &child : graph[node]) {
      if (!visited[child]) {
        findTopo(graph, child, visited);
      }
    }
    topo.push_back(node);
  }
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    n = graph.size();
    vector<int> visited(n, 0), isValid(n, 0), ans;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        findTopo(graph, i, visited);
      }
    }
    int N = topo.size();
    for (int i = 0; i < N; i++) {
      int is = 1;
      for (int &child : graph[topo[i]]) {
        if (isValid[child] == 0) {
          is = 0;
          break;
        }
      }
      isValid[topo[i]] = is;
      if (isValid[topo[i]]) {
        ans.push_back(topo[i]);
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};