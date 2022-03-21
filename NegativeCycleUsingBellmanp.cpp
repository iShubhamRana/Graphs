void bellman(vector<vector<int> > edges, int n, int v) {
	vector<int> d(n, INF);
	d[v] = 0;
	vector<int> p(n, -1);
	int x, m = edges.size();
	for (int i = 0; i < n; i++) {
		x = -1;
		for (int j = 0; j < m; j++ ) {
			auto edge = edges[j];
			if (d[edge[0]] < INF) {
				if (d[edge[0]] + edge[2] < d[edge[1]]) {
					d[edge[1]] = max(-INF , d[edge[0]] + edge[2]);
					p[edge[1]] = edge[0];
					x = edge[1];
				}
			}
		}
	}


	if (x == -1) {
		cout << "No cycle";
	} else {
		int y = x;
		for (int i = 0; i < n; i++)	y = p[y];
		vector<int> path;

		for (int cur = y;; cur = p[cur]) {
			path.push_back(cur);
			if (cur == y and path.size() > 1)
				break;
		}

		reverse(path.begin(), path.end());
		for (int i = 0; i < path.size(); i++) {
			cout << path[i] << " ";
		}

	}
}
