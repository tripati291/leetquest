class Solution {
public:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(i == 0) {
            if(j == nums.size() || nums[0] < nums[j])
                return 1;
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        int nottake= f(i-1,j, nums,dp);
        if(j==nums.size() || nums[i]<nums[j]) {
            take = 1 + f(i-1,i, nums,dp);
        }
    
        return dp[i][j]=max(take, nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n , vector<int>(n+1, -1));
        return f(n-1,n,nums,dp);

    }
};