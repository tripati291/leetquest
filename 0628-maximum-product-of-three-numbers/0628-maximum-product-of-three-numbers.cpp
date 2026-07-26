class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a=nums[0];
        int b=nums[1];
        reverse(nums.begin(), nums.end());
        int x=nums[0];
        int y=nums[1];
        int z=nums[2];
        return max(a*b*x , x*y*z);
    }
};