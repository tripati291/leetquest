class Solution {
public:
    int total = 0;
    int solve(vector<int>& nums, int i) {
        if (i < 2)
            return 0;

        int prev = solve(nums, i - 1);

        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            int curr = prev + 1;
            total += curr;
            return curr;
        }

        return 0;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        solve(nums, nums.size() - 1);
        return total;
    }
};