class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int maxi = 0;

        for(int a : set) {
            if(set.find(a - 1) == set.end()) {
                int start = a;
                int cnt = 1;

                while(set.find(start + 1) != set.end()) {
                    start++;
                    cnt++;
                }

                maxi = max(maxi, cnt);
            }
        }

        return maxi;
    }
};