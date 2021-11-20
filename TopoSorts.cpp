/********USING DFS********************/

void topo(int node, vector<int> adj[], vector<bool> &visited , stack<int> &s ) {

    visited[node] = true;

    for (auto edge : adj[node]) {
        if (!visited[edge]) {
            topo(edge, adj, visited, s);
        }
    }

    s.push(node);

}



vector<int> topoSort(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    stack<int> s;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topo(i, adj, visited, s);
        }
    }

    vector<int> res;

    while (!s.empty()) {
        res.push_back(s.top()); s.pop();
    }


    return res;

}

/*****************USING BFS**********************/