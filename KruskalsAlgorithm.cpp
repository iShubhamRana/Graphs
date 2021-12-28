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

bool Compare(vector<int> a , vector<int> b) {
	return a[2] < b[2];
}


int findParent(int a, vector<int> &parent) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = findParent(parent[a], parent);
}

void _union_(int a , int b, vector<int> &parent , vector<int> &rank) {
	if (rank[a] < rank[b]) {
		parent[a] = b;
	}
	else if (rank[a] > rank[b]) {
		parent[b] = a;
	}
	else {
		parent[b] = a;
		rank[a]++;
	}
}

int main() {

	checkjudge();
	//we need to store the graph in linear array not ajacency. I am assuming we are tkaing input as linear
	//in form of (node, node , weight)

	int n, m;
	//n->nodes , m->edges
	cin >> n >> m;
	vector<vector<int>> edges;

	for (int i = 0; i < m; i++) {
		vector<int> temp(3);
		cin >> temp[0] >> temp[1] >> temp[2];

		edges.push_back(temp);
	}

	for (auto edge : edges)
		cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;

	//sort the edges
	sort(edges.begin(), edges.end(), Compare);

	//inital work for disjoint set
	vector<int> parent(n);
	for (int i = 0; i < n; i++)
		parent[i] = i;
	vector<int> rank(n, 0);


	long int cost = 0;
	vector<vector<int> > mst;

	for (auto it : edges) {
		//if the two nodes are from differnt components then onlyt connect them else not
		if (findParent(it[0], parent) != findParent(it[1], parent) ) {
			mst.push_back(it);
			cost += it[2];
			_union_(it[0], it[1], parent, rank );
		}
	}


	cout << cost << "hi" << endl;
	for (auto edge : mst) {
		cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;
	}



	return 0;

}




