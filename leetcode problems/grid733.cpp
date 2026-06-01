// Leetcode 
// Problem => Flood Fill
// Link => https://leetcode.com/problems/$problem_name$/description/

// DFS
class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c,
             int startColor, int newColor) {

        int m = image.size();
        int n = image[0].size();

        if(r < 0 || c < 0 || r >= m || c >= n)
            return;

        // base case
        if(image[r][c] != startColor)
            return;

        image[r][c] = newColor;

        vector<pair<int, int>> dir = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        for(auto [dr, dc]: dir){
            int nr = r + dr;
            int nc = c + dc;

            dfs(image, nr, nc, startColor, newColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int startColor = image[sr][sc];

        if(startColor == color)
            return image;

        dfs(image, sr, sc, startColor, color);

        return image;
    }
};

// BFS |
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();

        int oldColor = image[sr][sc];

        if(oldColor == color)
            return image;

        queue<pair<int,int>> q;
        q.push({sr, sc});

        image[sr][sc] = color;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nc >= 0 &&
                   nr < m && nc < n &&
                   image[nr][nc] == oldColor) {

                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};

// DFS with stack | iterative DFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();

        int oldColor = image[sr][sc];

        if(oldColor == color)
            return image;

        stack<pair<int,int>> st;
        st.push({sr, sc});

        image[sr][sc] = color;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while(!st.empty()) {
            auto [r, c] = st.top();
            st.pop();

            for(int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nc >= 0 &&
                   nr < m && nc < n &&
                   image[nr][nc] == oldColor) {

                    image[nr][nc] = color;
                    st.push({nr, nc});
                }
            }
        }

        return image;
    }
};