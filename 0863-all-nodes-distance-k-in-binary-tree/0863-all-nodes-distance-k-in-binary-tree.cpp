/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left) {
                mp[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right) {
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
        queue<pair<TreeNode*, int>> qu;
        qu.push({target,0});
        unordered_set<TreeNode*> vis;
        vis.insert(target);
        while(!qu.empty()) {
            TreeNode* curr = qu.front().first;
            int dist = qu.front().second;
            qu.pop();
            if(dist == k) {
            ans.push_back(curr->val);
            continue;
            }
            if(curr->left && !vis.count(curr->left)) {
                vis.insert(curr->left);
                qu.push({curr->left, dist + 1});
            }
            if(curr->right && !vis.count(curr->right)) {
                vis.insert(curr->right);
                qu.push({curr->right, dist + 1});
            }
            if(mp.find(curr)!=mp.end() && !vis.count(mp[curr])) {
                vis.insert(mp[curr]);
                qu.push({mp[curr] , dist + 1});
            }
        }
        return ans;
    }
};