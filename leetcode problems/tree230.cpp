// Leetcode 
// Problem => Kth Smallest element in BST
// Link => https://leetcode.com/problems/problem_name/description/

// inorder traversal
class Solution {
public:
    vector<int> inorder;

    void dfs(TreeNode* root){
        if(!root) return;

        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return inorder[k-1];
    }
};

// inorder + count | best solution
class Solution {
public:
    int cnt = 0;
    int ans = 0;

    void inorder(TreeNode* root, int k) {

        if(!root)
            return;

        inorder(root->left, k);

        cnt++;

        if(cnt == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {

        inorder(root, k);

        return ans;
    }
};