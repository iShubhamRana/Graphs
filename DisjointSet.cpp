class DSU {
public:
    int N;
    vector<int> par , rank;
    DSU(int n) {
        par.assign(n, 0);
        rank.assign(n, 0);
        N = n;
        iota(par.begin(), par.end(), 0);
    }

    int findParent(int node) {
        if (par[node] == node) return node;
        return par[node] = findParent(par[node]);
    }

  void _union(int p, int q) {
            int i = findParent(p), j = findParent(q);
            if (i == j) return;
            if (rank[i] < rank[j]) {
                par[i] = j;  
            } else {
                par[j] = i;
                if (rank[i] == rank[j]) rank[i]++;
            }
          
        }

};
