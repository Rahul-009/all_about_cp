// Leetcode 
// Problem => Search a 2D Matrix
// Link => https://leetcode.com/problems/$problem_name$/description/

// flattened matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m * n - 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            int row = mid / n;
            int col = mid % n;

            int value = matrix[row][col];

            if(value == target)
                return true;

            if(value < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};

// Two binary search 
// find row first | then binary search on that row
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m - 1;

        while(top <= bottom) {

            int mid = top + (bottom - top) / 2;

            if(target < matrix[mid][0])
                bottom = mid - 1;

            else if(target > matrix[mid][n-1])
                top = mid + 1;

            else {

                int l = 0;
                int r = n - 1;

                while(l <= r) {

                    int m2 = l + (r - l) / 2;

                    if(matrix[mid][m2] == target)
                        return true;

                    if(matrix[mid][m2] < target)
                        l = m2 + 1;
                    else
                        r = m2 - 1;
                }

                return false;
            }
        }

        return false;
    }
};