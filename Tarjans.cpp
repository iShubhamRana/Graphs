/*
MUST THEORY TO REVISE TO UNDERSTAND THE INTUTITION:

Whenever we make a dfs call ,in the dfs tree there are 2 edges : forward and backedges.
backedges are not visited and forwards do the calling.

Now points:
1. backedges indicate that the node is connected to a ancestor(not direct parent);
2.  From prev point we can say that backedges can't be bridge.
3. Forward edges are only candidates for bridges.

Algos:
intime array:maintains the time when the node was forst reached.
lowtime: lowest ancestor that can be reached from that node.

1. mark visited , set the intime.
2. go through the edges and ignore the direct parent.
3.  if an edge is a backedge, record the ancestor it is connecting to .
4. make a dfs call in forward edge.
5. After the dfs call in the forward edge, perform checking. If the lowtime of node connected through
that edge is greater than the intime of current node means it is a bridge.
6. After checking the path , update the lowtime of current node as any ancestor which could have been reached
through the connected node can also be reached through this node if the edge is safe.

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
int timer;

void dfs(int source, int parent ) {
    visited[source] = true;
    intime[source] = lowtime[source] = timer++;

    for (auto child : adj[source]) {
        if (child == parent)
            continue;
        else if (visited[child]) {
            //this is a backedge
            lowtime[source] = min(lowtime[source], intime[child]);
        }
        else {
            //this is a forward edge
            dfs(child, source);

            //check condition
            if (lowtime[child] > intime[source]) {
                //this is a bridge
                cout << source << " -> " << child;
            }

            //updating the lowtime
            lowtime[source] = min(lowtime[source], lowtime[child]);
        }
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