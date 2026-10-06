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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode* , long long>> q;
        q.push({root,0});
        long long maxi =0;
        while(!q.empty()) {
            int sz= q.size();
            long long st;
            long long end;
            long long temp = q.front().second;
            for(int i=0; i<sz; i++) {
                TreeNode* cur = q.front().first;
                long long ind = q.front().second - temp;
                q.pop();
                if(i==0) {
                    st = ind;
                }
                if(i==sz-1) {
                    end= ind;
                }
                if(cur->left) {
                    q.push( {cur->left , ind*2 + 1});
                }
                if(cur->right) {
                    q.push( {cur->right , ind*2 + 2});
                }
            }
            maxi = max(maxi , end - st + 1);
        }
        return maxi;
    } 
};