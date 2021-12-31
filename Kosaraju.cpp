/*
THEORY SUMMARY:
1. GRAPH AND TRANSPOSED GRAPH HAVE SAME CONNECTED COMPONENTS
2. CONDENSATION GRAPH HAS NO CYCLE , WE CAN PROVE
3. A CONDENSATION GRAPH IS ACYCLIC.
4. IF THERE IS AN EDGE FROM SCC_I TO SCC_J THEN , OUTTIME OF SCC_I > SCC_J
5. COMPONENT WITH HIGHEST OUTTIME WILL HAVE INDEGREE 0


*/


#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;
void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt" , "w" , stdout);
#endif
}

vector<int> adj[100001], tr[100001];
vector<int> order;
vector<bool> visited(100001, false);
vector<int> SCC;

void dfs(int i) {
    visited[i] = true;
    for (auto child : adj[i]) {
        if (!visited[child])
            dfs(child);
    }
    order.push_back(i);
}
void dfs1(int node) {
    visited[node] = true;
    for (auto child : tr[node]) {
        if (!visited[child])
            dfs1(child);
    }
    SCC.push_back(node);
}

int main() {

    checkjudge();
    int n,  m;
    cin >> n >> m;

    while (m--) {
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        tr[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(i);
    }

    for (int i = 1; i <= n; i++)
        visited[i] = false;



    for (int i = 1; i <= n; i++) {
        if (!visited[order[n - i]]) {
            SCC.clear();
            dfs1(order[n - i]);
            cout << "dfs called for node" << order[n - i] << "and SCC is";
            for (int node : SCC)
                cout << node << " ";
            cout << endl;
        }
    }



    return 0;

}