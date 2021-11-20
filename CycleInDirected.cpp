//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

bool checkCycle(int node , vector<int> adj[], vector<bool> &visited, vector<bool> &dfsvis) {

	visited[node] = true;
	dfsvis[node] = true;

	for (auto edge : adj[node]) {
		if (visited[edge] and dfsvis[edge])
			return true;
		else if (!visited[edge]) {
			bool res = checkCycle(edge, adj, visited, dfsvis);

			if (res == true)
				return true;
		}
		else {}
	}

	dfsvis[node] = false;
	return false;

}


bool isCyclic(int V, vector<int> adj[]) {

	vector<bool> visited(V, false);
	vector<bool>  dfsvis(V, false);

	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			bool res = checkCycle(i, adj, visited, dfsvis);
			if (res)
				return true;
		}
	}

	return false;
}