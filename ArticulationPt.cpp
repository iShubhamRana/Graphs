
/*
    THE ALGORITHM IS ALMOST SAME AS BRIDGES:

    but here if the lowtime of child >= the intime of current node then it is an articulation point
    With this logic root will always comeout to be root. SO we will handle that and modify

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


vector<int> adj[10001];
vector<int> lowtime(10001);
vector<int> intime(10001);
vector<bool> visited(10001, false);
int timer = 0;

void dfs(int node, int p = -1) {
    visited[node] = true;
    intime[node] = lowtime[node] = timer++;
    int children = 0;

    for (auto child : adj[node]) {
        //parent
        if (child == p)
            continue;
        if (visited[child]) {
            //backedge
            lowtime[node] = min(lowtime[node], intime[child]);
        }
        else {
            dfs(child, node);
            lowtime[node] = min(lowtime[node], lowtime[child]);

            if (lowtime[child] >= intime[node] and p != -1)
                cout << node << "is an articulation point" << endl;
            children++;
        }
    }

    if (p == -1 and children > 1) {
        cout << node << " is an articulation point";
    }

}

int main() {

    checkjudge();

    int n , m;
    cin >> n >> m;
    int x, y;
    while (m--)
        cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
    //set invalid parent of root node
    dfs(1, -1);



    return 0;

}