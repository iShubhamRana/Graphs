#include <iostream>

int parent[100000];
int rank[100000];

void makeSet(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}

int findParent(int node) {
	if (parent[node] == node)
		return node;

	return parent[node] = findParent(parent[node]);
}


void _union_(int u , int v) {
	u = findParent(u);
	v = findParent(v);
	
	if(u==v) return ;

	if (rank[u] < rank[v] {
	parent[u] = v;
	}
	else if (rank[u] > rank[v]) {
	parent[v] = u;
	}
	else {
		parent[v] = u;
		rank[u]++;
	}

}

int main() {
	return 0;
}
