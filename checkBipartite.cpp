bool isBipartite(int V, int n, vector<int>adj[]) {

    vector<int>  colors(V, -1);
    queue<int > q;

    q.push(n);
    colors[n] = 1;

    while (!q.empty()) {
        auto x = q.front(); q.pop();

        for (auto edges : adj[x]) {
            if (colors[edges] == -1) {
                colors[edges] = (colors[x] == 1) ? 0 : 1;
                q.push(edges);
            }
            else {
                if (colors[edges] == colors[x])
                    return false;
            }
        }

    }

    return true;


}