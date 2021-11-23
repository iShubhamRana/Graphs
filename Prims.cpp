
//Optimal implementation O(nlogn)
vector<int> prims(int N, vector<pair<int, int>> adj[]) {

    priority_queue<pair<int, int>, vector<pair<int, int>> , Compare > q;

    vector<int> key(N, INT_MAX), parent(N, -1);
    vector<bool> mst(N, false);
    key[0] = 0;

    q.push(make_pair(0, 0));

    for (int i = 0; i < N - 1; i++) {

        auto x = q.top(); q.pop();
        int node = x.second;

        mst[node] = true;

        for (auto edge : adj[node]) {
            int weight = edge.second;
            int v = edge.first;

            if (!mst[v] and weight < key[v]) {
                key[v] = weight;
                parent[v] = node;
                q.push(make_pair(key[v], v));
            }

        }

    }

    return parent;

}
