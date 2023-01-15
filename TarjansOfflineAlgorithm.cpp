/*
SIMPLE THING TO UNDERSTAND , IF WE ARE ON V AND U IS ALREADY VISITED AND U IS NOT IN THE SUBTREE OF V THEN THE NODE WHICH SENT THE DFS CALL TO V(NOT DIRECT PARENT)
IS THE LCA , SO INORDER TO FIND THAT NODE WE CAN MAINTAIN A DSU AND THEN MERGE THE SUBTREES INTO THAT NODE AS SOON AS THE DFS CALLS ON THE CHILDREN TREES
FINISH, THUS CREATING A LARGE ONE SUBTREE

*/




/*
IN FUTURE , I WILL DEFINITELY BE PROUD OF THE CURRENT ME
JAI SHRI KRISHNA !!!
*/


/*

WORK ON COMING UP WITH NICE TESTCASES LIKE I WAS PROVIDED WITH ONE IN CONDEFORCES
DISCUSS SECTION

BEFORE GOINF FORWARD WITH AN OBSERVATION , TRY VALIDATING IT WITH A COUNTER EXAMPLE
*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int>  pi;

/***************************************************************************************/
//access keywords
#define F first
#define S second
#define PB push_back
#define inf INT_MAX
#define INF 1e18

// #define MP make_pair
// // ***********************************************************************************
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define REV_REP(i,a,b) for(int i=a;i>=b;i--)
#define inputVectori(v) for(auto &x:v) cin>>x;
#define printVectori(v) for(auto &x:v) cout<<x<<" ";
#define all(a) a.begin() , a.end()
/*****Remember inbuilt c++ functions*************************/

// next_permutation(), __builtin_popcount()

/***********************************************************/
const int mod  = 998244353 ;

inline void newLine() {
    cout << "\n";
}

void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
}


vector<ll> factorial;
void preprocess(int n) {
    factorial.push_back(1);
    for (int i = 1; i <= n; i++) {
        ll curr = (factorial.back() * i) % mod;
        factorial.push_back(curr);
    }
}

ll binaryExp(ll x , ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

ll nCr(ll n, ll r) {
    if (n < r) return 0;
    ll fac1 = factorial[n];
    ll fac2 = binaryExp(factorial[n - r], mod - 2);
    ll fac3 = binaryExp(factorial[r], mod - 2);
    ll ans = (fac1 * fac2) % mod;
    ans = (ans * fac3) % mod;
    return ans;
}


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


vector<vector<int> > adj;
vector<bool> visited;
vector<vector<pair<int, int> > > queries;
vector<int> ans;
vector<int> ancestor;


void dfs(int u , DSU &s) {

    visited[u] = true;
    //ancestor is not a part of disjoint set , its maintained
    ancestor[u] = u;
    for (int v : adj[u]) {
        if (visited[v]) continue;
        dfs(v, s);
        s._union(u, v);
        ancestor[s.findParent(u)] = u;
    }

    // we answer queries later so that all the queries(u,v) where u is in the subtree of v
    //we can calculate the ans after dfsing
    for (auto q : queries[u]) {
        int other_node = q.first , index = q.second;
        if (visited[other_node]) {
            //other node jis set me hai vo ab hai , usi set se hmare uppar call ayi and therefore
            ans[index] = ancestor[s.findParent(other_node)];
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    visited.resize(n);
    adj.resize(n);
    queries.resize(n);
    ancestor.resize(n);

    for (int i = 1; i < n; i++) {
        int p; cin >> p; p--;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    ans.resize(m);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a-- , b--;
        queries[a].push_back({b, i});
        queries[b].push_back({a, i});
    }

    DSU s(n);
    dfs(0, s);
    for (int i = 0; i < m; i++) {
        cout << ans[i] + 1 << endl;
    }


}

int32_t main() {
    checkjudge();
    /*********************************************************************/
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*************************************************************************************/
    int t = 1;
    // cin >> t;
    for (int z = 1; z <= t; z++) {
        solve();
    }

}




//Hare Krishna !! Hare Ram
