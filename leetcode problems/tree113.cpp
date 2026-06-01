// Leetcode 
// Problem => path sum II
// Link => https://leetcode.com/problems/problem_name/description/


// O(n)
class Solution {
private:
    vector<vector<int>> ans;

    void dfs(TreeNode* root, vector<int> &path, int targetSum, int currentSum){
        if(!root) return;

        currentSum += root->val;
        path.push_back(root->val);
        //leaf node
        if(!root->left && !root->right){
            if(currentSum == targetSum){
                ans.push_back(path);
            }
        }

        dfs(root->left, path, targetSum, currentSum);
        dfs(root->right, path, targetSum, currentSum);

        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int currentSum = 0;
        vector<int> path;
        dfs(root, path, targetSum, currentSum);
        return ans;
    }
};