//graph template for numeric edges

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
};

//graph template for string nodes


class Node {
public:
    string name;
    list <string> nbrs;
    Node(string name) {
        this->name = name;
    }
};


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

