/*BINARY LIFTING    */

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

vector<ll> adj[1000001];
vector<vector<int> > up;
int l, n;
int timer;
vector<int> intime, outtime;

void dfs(int node, int parent) {
    up[node][0] = parent;
    intime[node] = ++timer;

    for (int i = 1; i <= l; i++) {
        up[node][i] = up[up[node][i - 1]][i - 1];
    }

    for (auto child : adj[node]) {
        if (child != parent)
            dfs(child, node);
    }

    outtime[node] = ++timer;

}

void preprocess(int root) {
    intime.resize(n);
    outtime.resize(n);
    timer = 0;
    l = log2(n);
    up.assign(n, vector<int> (l + 1));
    dfs(root, root);
}

bool is_ancestor(int u, int v) {
    if (intime[u] <= v and outtime[u] >= v) {
        return true;
    }
    return false;
}

int query(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    //find higest ancestor of u not an ancestor of v
    for (int i = l; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }

    return up[u][0];
}

int main() {

    checkjudge();
    int m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    //assuming root to be 1
    int root = 1;

    preprocess(root);

    cout << query(5, 9);
    return 0;

}