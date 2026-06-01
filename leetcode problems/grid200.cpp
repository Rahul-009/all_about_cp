// Leetcode 
// Problem => Number of islands
// Link => https://leetcode.com/problems/$problem_name$/description/


// DFS | O(V+E)
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();

        if(r<0 || c<0 || r>=rows || c>=cols)
            return;

        if(grid[r][c] == '0') return;

        grid[r][c] = '0';
        
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int islands = 0;

        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
};

// BFS | O(V+E)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == '1') {

                    islands++;

                    queue<pair<int,int>> q;
                    q.push({i, j});

                    grid[i][j] = '0';

                    while(!q.empty()) {

                        auto [r, c] = q.front();
                        q.pop();

                        for(int k = 0; k < 4; k++) {

                            int nr = r + dr[k];
                            int nc = c + dc[k];

                            if(nr >= 0 && nc >= 0 &&
                               nr < m && nc < n &&
                               grid[nr][nc] == '1') {

                                grid[nr][nc] = '0';
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};

// Disjoint Set Union