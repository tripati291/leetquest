class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n= nums.size();
        int peak=0;
        long long total=0;
        long long  sum=0;
        for(int i=0; i<n-1; i++) {
            if(nums[i+1]-nums[i]<0) {
                peak= i;
                break;
            }
        }

        for(int i = 0; i <= peak; i++)
           total += nums[i];

        for(int i = peak; i < n; i++)
            sum += nums[i];
        if(total>sum) return 0;
        else if (total<sum) return 1;
        else return -1;
    }
};