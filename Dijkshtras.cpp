class Compare {
public:
    bool operator()(pair<int, int> &a , pair<int, int> b) {
        return a.first > b.first;
    }
};

vector<int> dijkshtras(int N, int s, vector<pair<int, int>> adj[]) {

    priority_queue<pair<int, int>, vector<pair<int, int>> , Compare > q;
    vector<int> dis(N, INT_MAX);
    dis[s] = 0;
    q.push(make_pair(0, s));

    while (!q.empty()) {
        auto x = q.top(); q.pop();
        int prev = x.second;

        for (auto edges : adj[prev]) {
            int next = edges.first;
            int nextDist = edges.second;

            if (dis[next] > dis[prev] + nextDist) {
                dis[next] = dis[prev] + nextDist;
                q.push(make_pair(dis[next], next));
            }

        }

    }

    return dis;
}

