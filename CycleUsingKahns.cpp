// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

  bool isCyclic(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++) {
      for (auto edges : adj[i]) {
        indegree[edges]++;
      }
    }

    queue<int> q;

    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    int count = 0;
    while (!q.empty()) {
      count++;

      int node = q.front(); q.pop();
      for (auto edges : adj[node]) {
        indegree[edges]--;
        if (indegree[edges] == 0)
          q.push(edges);
      }
    }

    if (count == V)return false;
    return true;

  }
};