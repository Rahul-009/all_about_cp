// Leetcode 
// Problem => Surrounded Regions
// Link => https://leetcode.com/problems/$problem_name$/description/


// DFS Bruteforce 
class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& board,
             int r, int c,
             vector<pair<int,int>>& cells,
             bool& touchesBorder) {

        if(r < 0 || c < 0 || r >= m || c >= n)
            return;

        if(board[r][c] != 'O')
            return;

        board[r][c] = '#';   // visited

        cells.push_back({r, c});

        if(r == 0 || c == 0 || r == m-1 || c == n-1)
            touchesBorder = true;

        dfs(board, r+1, c, cells, touchesBorder);
        dfs(board, r-1, c, cells, touchesBorder);
        dfs(board, r, c+1, cells, touchesBorder);
        dfs(board, r, c-1, cells, touchesBorder);
    }

    void solve(vector<vector<char>>& board) {

        m = board.size();
        n = board[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {

                if(board[i][j] == 'O') {

                    vector<pair<int,int>> cells;
                    bool touchesBorder = false;

                    dfs(board, i, j, cells, touchesBorder);

                    char fillChar =
                        touchesBorder ? 'O' : 'X';

                    for(auto& p : cells) {
                        board[p.first][p.second] = fillChar;
                    }
                }
            }
        }
    }
};

// DFS on border only | observation
class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& board, int r, int c) {

        if(r < 0 || c < 0 || r >= m || c >= n)
            return;

        if(board[r][c] != 'O')
            return;

        board[r][c] = '#';

        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }

    void solve(vector<vector<char>>& board) {

        m = board.size();
        n = board[0].size();

        // Left and right borders
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O')
                dfs(board, i, 0);

            if(board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }

        // Top and bottom borders
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O')
                dfs(board, 0, j);

            if(board[m - 1][j] == 'O')
                dfs(board, m - 1, j);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == 'O')
                    board[i][j] = 'X';

                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};

