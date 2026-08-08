class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int index, vector<int>& current) {
        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        solve(nums, index + 1, current);
        current.pop_back();
        solve(nums, index + 1, current);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        solve(nums, 0 , curr) ;
        return ans;
    }
};