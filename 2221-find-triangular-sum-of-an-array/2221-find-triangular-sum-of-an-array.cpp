class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n= nums.size();
        // vector<int> old;
        // old = nums;
        // vector<int> nya;
        while(n>1) {
            for(int i=0 ; i< n -1 ; i++ ) {
                nums[i] = (nums[i] + nums[i+1])%10;
            }
            n--;
           // old = nya;
            // nya= vector<int> ();
        }
        return nums[0];
    }
};