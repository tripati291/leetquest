class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int m=0;
        for(int i=1; i<n; i++) {
            if(nums[i] < nums[i-1]) {
                m=i;
            }
        }
        return nums[m];
    }
};