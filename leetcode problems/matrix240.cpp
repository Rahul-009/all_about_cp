// search in a 2D matrix II

/*

1   4   7   11  15
2   5   8   12  19
3   6   9   16  22
10 13  14   17  24
18 21  23   26  30


start from top right corner

At each step:
Move left ⇒ eliminate one whole column.
Move down ⇒ eliminate one whole row.

You never revisit a cell.

*/

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