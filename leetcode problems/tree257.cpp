// Leetcode 
// Problem => Binary Tree Paths
// Link => https://leetcode.com/problems/problem_name/description/

// preOrder 
class Solution {
public:
    vector<string> ans;

    void preorder(TreeNode* root, string path){
        if(!root) return;

        if(path.empty()){
            path = to_string(root->val);
        }else{
            path+="->" + to_string(root->val);
        }

        // process root first
        if(!root->left && ! root->right){
            ans.push_back(path);
        }

        preorder(root->left, path);
        preorder(root->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        preorder(root, "");
        return ans;
    }
};

// DFS = preorder
class Solution {
public:
    vector<string> ans;

    void dfs(TreeNode* node, string path) {

        if(!node)
            return;

        path += to_string(node->val);

        if(!node->left && !node->right) {
            ans.push_back(path);
            return;
        }

        path += "->";

        dfs(node->left, path);
        dfs(node->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        dfs(root, "");

        return ans;
    }
};
