void topo(int n, vector<pair<int, int> > adj[], stack<int> &s, vector<bool> &visited) {
    visited[n] = true;

    for (auto edge : adj[n]) {
        if (!visited[edge.first]) {
            topo(edge.first, adj, s, visited);
        }
    }
    s.push(n);
}

vector<int> toposort(int N, vector<pair<int, int> > adj[]) {

    vector<bool> visited(N);
    stack<int> s;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            topo(i, adj, s, visited);
        }
    }

    vector<int> res;

    while (!s.empty()) {
        res.push_back(s.top()); s.pop();
    }


    return res;
}



vector<int>  shortestpathInDag(int N, int source , vector<pair<int, int> > adj[]) {

    //to prevent multiple dfs calls to get shortest path we use toposort
    //for all the edges that might income into a node we find minimum and thi way we don't have to update paths preventing multiple dfs calls
    vector<int> res = toposort(N, adj);
    vector<int> dis(N, INT_MAX);
    dis[source] = 0;

    for (auto x : res) {
        if (dis[x] != INT_MAX) {
            for (auto edge : adj[x]) {
                if (edge.second + dis[x] <= dis[edge.first]) {
                    dis[edge.first] = edge.second + dis[x];
                }
            }
        }
    }
    return dis;
}
