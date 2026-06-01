// Leetcode 
// Problem => rotting oranges
// Link => https://leetcode.com/problems/$problem_name$/description/


// solution 1 | multi source bfs
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){

                if(grid[r][c] == 2)
                    q.push({r,c});

                else if(grid[r][c] == 1)
                    fresh++;
            }
        }

        if(fresh == 0)
            return 0;

        int minutes = 0;

        vector<pair<int,int>> dir = {
            {1,0},{-1,0},{0,1},{0,-1}
        };

        while(!q.empty() && fresh > 0){

            int size = q.size();

            minutes++;

            for(int i=0;i<size;i++){

                auto [r,c] = q.front();
                q.pop();

                for(auto [dr,dc] : dir){

                    int nr = r + dr;
                    int nc = c + dc;

                    if(nr<0 || nc<0 ||
                       nr>=rows || nc>=cols)
                        continue;

                    if(grid[nr][nc] != 1)
                        continue;

                    grid[nr][nc] = 2;

                    fresh--;

                    q.push({nr,nc});
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};


// solution 2 | multi source bfs | carry time with position
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<tuple<int, int, int>> q;
        int fresh = 0;

        // add all rotten oranges as starting points
        for(int r = 0; r<rows; r++){
            for(int c = 0; c<cols; c++){
                if(grid[r][c] == 2){
                    q.push({r, c, 0});
                }
                else if(grid[r][c] == 1){
                    fresh++;
                }
            }
        }

        int minutes = 0;
        
        vector<pair<int,int>> dir = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        while(!q.empty()){
            auto [r, c, time] = q.front();
            q.pop();

            minutes = max(minutes, time);

            for(auto [dr, dc]: dir){
                int nr = r+dr;
                int nc = c+dc;

                if(nr < 0 || nc<0 || nr>=rows || nc >=cols){
                    continue;
                }

                if(grid[nr][nc] != 1) continue;

                // Rot the fresh orange
                grid[nr][nc] = 2;
                fresh--;

                q.push({nr, nc, time+1});
            }
        }
        return fresh == 0 ? minutes:-1;
    }
};