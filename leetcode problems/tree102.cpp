// Leetcode 
// Problem => Binary Tree Level Order Traversal
// Link => https://leetcode.com/problems/$problem_name$/description/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> levelVals;

            for(int i = 0; i<levelSize; i++){
                TreeNode* node = q.front();
                q.pop();

                levelVals.push_back(node->val);

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }

            ans.push_back(levelVals);
        }
        return ans;
    }
};