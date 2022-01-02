#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define INF INT_MAX

using namespace std;
void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt" , "w" , stdout);
#endif
}

struct edge {
    int a, b, cost;
};

vector<edge> edges(1000001);
/*
Complexity O(EV)
*/
void bellman(int source, int n) {
    vector<int> dis(n + 1, INF);
    dis[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        bool flag = false;

        for (auto x : edges) {
            if (dis[x.a] < INF) {
                if (dis[x.b] > dis[x.a] + x.cost) {
                    dis[x.b] = min(dis[x.b], dis[x.a] + x.cost);
                    flag = true;
                }
            }
        }

        if (!flag)
            break;

    }
    for (int i = 1; i < n + 1; i++)
        cout << dis[i] << " ";

    cout << endl;
}

/*
Shortest Path Faster Algorithm

*/
vector < vector<pair<int, int> > adj;
bool spfa(int s, vector<int> &d) {
    int n = adj.size();
    for (auto &x : d)
        x = INF;
    vector<int> cnt(n, 0);
    vector<int> inqueue(n, false);
    queue<int> q;
    d[s] = 0, inqueue[s] = true, q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push(to);
                inqueue[to] = true;
                cnt[to]++;

                if (cnt[to] > n)
                    return false;
                //negative cycle

            }


        }

    }


}


int main() {

    checkjudge();
    int n, m;
    cin >> n >> m;

    while (m--) {
        edge temp;
        cin >> temp.a >> temp.b >> temp.cost;
        edges.pb(temp);
    }


    bellman(1, 4);



    return 0;

}