// Leetcode 
// Problem => path sum
// Link => https://leetcode.com/problems/$problem_name$/description/


// Bruteforce | go to leaf then do sum | backtrack
class Solution {
public:
    bool ans = false;

    void dfs(TreeNode* root, vector<int> &path, int targetSum){
        if(!root) return;

        path.push_back(root->val);

        // leaf node
        if(!root->left && !root->right){
            int sum = 0;

            for(int x: sum){
                sum += x;
            }

            if(sum == targetSum)
                ans = true;
        }

        dfs(root->left, path, targetSum);
        dfs(root->right, path, targetSum);

        path.pop_back();
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};

// running sum (n)
class Solution {
public:
    bool dfs(TreeNode* root, int currentSum, int targetSum){
        if(!root) return false;

        currentSum += root->val;

        //Leaf node
        if(!root->left && !root->right){
            return currentSum == targetSum;
        }

        return dfs(root->left, currentSum, targetSum) || dfs(root->right, currentSum, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};