class Solution {
public:
    bool search(vector<int>& nums, int target) {
        bool found = true;
        int n= nums.size();
        int m=0;
        for(int i=1; i<n; i++) {
            if(nums[i] < nums[i-1]) {
                m=i;
                break;
            }
        }
        int low=0, high=0;
        if(m==0) {
            low=0;
            high=n-1;
        }
        else if(target >= nums[0] && target <= nums[m-1]) {
            low=0;
            high=m-1;
        }
        else {
            low = m;
            high= n-1;
        }
        while(low<= high) {
            int mid= low + (high - low)/2;
            if(target == nums[mid]) return found;
            else if(nums[mid] > target) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return false;
    }
};