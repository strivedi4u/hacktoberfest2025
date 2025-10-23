void solve(vector<vector<char>>& board) {
    int m = board.size();
    if (m == 0) return;
    int n = board[0].size();

    vector<vector<int>> visited(m, vector<int>(n, 0));
    queue<pair<int, int>> q;

    // Step 1: Push all border 'O's into the queue and mark visited
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O' && (i == 0 || j == 0 || i == m - 1 || j == n - 1)) {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    // Step 2: BFS from border 'O's
    int dr[] = {1, 0, -1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = row + dr[i];
            int c = col + dc[i];

            if (r >= 0 && r < m && c >= 0 && c < n) {
                if (board[r][c] == 'O' && visited[r][c] == 0) {
                    visited[r][c] = 1;
                    q.push({r, c});
                }
            }
        }
    }

    // Step 3: Flip unvisited 'O's to 'X'
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O' && visited[i][j] == 0) {
                board[i][j] = 'X';
            }
        }
    }
}
