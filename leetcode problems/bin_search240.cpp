// problem - Search a 2D matrix II

// brute force | O(mn) time | O(1) memory
for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
        if(matrix[i][j] == target)
            return true;
    }
}
return false;

// binary search every row | O(m log n) time | O(1) memory
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {

            // Optional pruning
            if (target < matrix[i][0] || target > matrix[i][n - 1])
                continue;

            int left = 0;
            int right = n - 1;

            while (left <= right) {

                int mid = left + (right - left) / 2;

                if (matrix[i][mid] == target)
                    return true;

                if (matrix[i][mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return false;
    }
};

// eliminationg logic
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n - 1;

        while (row < m && col >= 0) {

            if (matrix[row][col] == target)
                return true;

            if (matrix[row][col] > target)
                col--;
            else
                row++;
        }

        return false;
    }
};