int min_dice_throws(int n, vector<pair<int, int> > snakes, vector<pair<int, int> > ladders) {

    int *board = new int[n + 1] {0};

    for (auto snake : snakes) {
        int s = snake.first;
        int e = snake.second;
        board[s] = e - s;
    }

    for (auto ladder : ladders) {
        int s = ladder.first;
        int e = ladder.second;
        board[s] = e - s;
    }

    Graph g(n + 1);

    for (int i = 1; i < n; i++) {
        for (int dice = 1; dice <= 6; dice++) {
            int v = i + dice;
            v += board[v];
            if (v <= n)
                g.addEdge(i, v);
        }
    }



    return g.shortestPathUsingBFS(1, n);


}