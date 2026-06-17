class Solution {
public:
    int f(int i, int prev, vector<int>& nums,
          vector<vector<int>>& dp) {

        if(i == nums.size()) return 0;

        if(dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        int notTake = f(i + 1, prev, nums, dp);
        int take = 0;
        if(prev == -1 || nums[i] % nums[prev] == 0) {
            take = 1 + f(i + 1, i, nums, dp);
        }

        return dp[i][prev + 1] = max(take, notTake);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        f(0, -1, nums, dp);
        vector<int> ans;
        int i = 0;
        int prev = -1;

        while(i < n) {

            int notTake = f(i + 1, prev, nums, dp);
            int take = 0;
            if(prev == -1 || nums[i] % nums[prev] == 0)
                take = 1 + f(i + 1, i, nums, dp);

            if(take >= notTake &&
               (prev == -1 || nums[i] % nums[prev] == 0)) {
                ans.push_back(nums[i]);
                prev = i;
            }
            i++;
        }
        return ans;
    }
};