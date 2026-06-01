// Leetcode 
// Problem => Binary Tree Maximum Path Sum
// Link => https://leetcode.com/problems/problem_name/description/

/* Pattern => 
    At each node:

    1. Compute information from left child.
    2. Compute information from right child.
    3. Update global answer using BOTH sides.
    4. Return ONE side to parent.
*/



// DFS 
class Solution {
public:
    int ans = INT_MIN;

    int dfs(TreeNode* node){
        if(!node){
            return 0;
        }

        // left subtree max chain sum
        int leftGain = max(0, dfs(node->left));
        // right subtree max chain sum
        int rightGain = max(0, dfs(node->right));

        // calculate path sum through node
        int currentPathSum = leftGain + node->val + rightGain;
        ans = max(ans, currentPathSum);

        // return 
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

