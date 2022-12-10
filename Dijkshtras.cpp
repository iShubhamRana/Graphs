const int N = 1e5 + 10;
bool visited[N];
vector<pi> adj[N];
ll dist[N];


void shortespath(int node) {
    priority_queue<pair<ll, int> > q;
    q.push({0, 1});
    dist[1] = 0;

    while (q.size()) {
        auto p = q.top(); q.pop();
        int node = p.second;

        if (visited[node]) continue;
        visited[node] = 1;

        // v = {node, distance}
        for (auto v : adj[node]) {
            if (dist[v.first] > dist[node] + v.second) {
                dist[v.first] = dist[node] + v.second;
                q.push({ -dist[v.first] , v.first});
            }
        }

    }

}

