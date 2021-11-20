


vector<int> topoSort(int N, vector<int> adj[])
{
    queue<int> q;
    vector<int> indegree(N, 0);

    for (int i = 0; i < N; i++) {
        for (auto edge : adj[i]) {
            indegree[edge]++;
        }
    }

    //push nodes with indegree 0
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        topo.push_back(node);
        for (auto edge : adj[node]) {
            indegree[edge]--;
            if (indegree[edge] == 0) {
                q.push(edge);
            }
        }


    }


    return topo;


}
