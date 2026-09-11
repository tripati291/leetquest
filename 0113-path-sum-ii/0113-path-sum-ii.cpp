/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node, int tgt, int sum, vector<int>& path, vector<vector<int>>& ans) {
        if(!node) return;
        sum += node->val;
        path.push_back(node->val);

        if(!node->left && !node->right && sum==tgt) {
            ans.push_back(path);
        }

        dfs(node->left, tgt, sum, path, ans);
        dfs(node->right, tgt, sum, path, ans);

        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        
        dfs(root, targetSum, 0, path, ans);
        return ans;
    }
};