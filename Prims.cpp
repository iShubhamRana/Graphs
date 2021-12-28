//For a complete graph with n vertices, Cayley's formula gives the number of spanning trees as nn −





//O(n*n)implementation
vector<int> prims(int N , vector<pair<int, int> > adj[]) {
    vector<int> key(N, INT_MAX);
    vector<int> parent(N, -1);
    vector<bool>mst(N, false);

    key[0] = 0;

    for (int count = 0; i < N - 1 ; count++) {
        int mini = INT_MAX;
        int node;

        for (int v = 0; v < N; v++) {
            if (!mst[v] and key[v] < mini) {
                mini = key[v];
                node = v;
            }
        }

        mst[node] = true;

        for (auto edges : adj[node]) {
            if (!mst[edges.first] and edges.second < key[edges.first]) {
                key[edges.first] = edges.second;
                parent[edges.first] = node;
            }
        }

    }

    return parent;
}











//Optimal implementation O(nlogn)
vector<int> prims(int N, vector<pair<int, int>> adj[]) {

    priority_queue<pair<int, int>, vector<pair<int, int>> , Compare > q;

    vector<int> key(N, INT_MAX), parent(N, -1);
    vector<bool> mst(N, false);
    key[0] = 0;

    q.push(make_pair(0, 0));

    //code needs a change . will update soon
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
