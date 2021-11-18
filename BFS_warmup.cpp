
#include<bits/stdc++.h>
#define ll long int
#define pb push_back

using namespace std;
void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt" , "w" , stdout);
#endif
}




class Graph {

    list <int> *l;
    int V;

public:
    Graph(int v) {
        V = v;
        l = new list<int> [v];
    }
    void addEdge(int i, int j , bool undir = true) {
        l[i].push_back(j);
        if (undir) {
            l[j].push_back(i);
        }
    }

    void printAdjList() {
        for (int i = 0; i < V; i++) {
            cout << i << "-->";
            for (auto node : l[i])
                cout << node << ",";
            cout << "\n";

        }
    }

    //complexity O(V+E) for adjacency list

    void bfs(int n) {

        queue<int> q;

        bool *visited = new bool[V] {0};

        q.push(n);
        visited[n] = true;

        while (!q.empty()) {
            int x = q.front(); q.pop();
            cout << x;

            for (auto edges : l[x]) {
                if (!visited[edges]) {
                    visited[edges] = true;
                    q.push(edges);
                }
            }

        }

    }

    void shortestPathUsingBFS(int);
    void displayShortestpath(int, int);

};



//single shortest path using bfs for undirected graph
void Graph::shortestPathUsingBFS(int n) {

    bool *visited = new bool[V] {0};
    int *distances = new int[V];

    queue<int> q;
    q.push(n);
    visited[n] = true;

    while (!q.empty()) {
        int x = q.front(); q.pop();

        for (auto edges : l[x]) {
            if (!visited[edges]) {
                visited[edges] = true;
                distances[edges] = 1 + distances[x];
                q.push(edges);
            }
        }

    }

    for (int i = 0; i < V; i++) {
        cout << i << "--> " << distances[i] << endl;
    }


}


void Graph::displayShortestpath(int n1, int n2) {
    //store the parents using bfs
    bool *visited = new bool[V] {0};
    int *parent = new int [V];
    queue<int> q;
    q.push(n1);
    parent[n1] = n1;
    visited[n1] = true;

    while (!q.empty()) {
        int x = q.front(); q.pop();

        for (auto edges : l[x]) {
            if (!visited[edges]) {
                visited[edges] = true;
                parent[edges] = x;
                q.push(edges);
            }
        }

    }

    int x = n2;
    while (x != n1) {
        cout << x << "-->";
        x = parent[x];
    }

    cout << n1;



}

int main() {

    checkjudge();

    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);


    g.displayShortestpath(1, 5);



    return 0;

}
