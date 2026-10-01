class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int maxi = 0;

        for(int num : set) {
            if(set.find(num - 1) == set.end()) {
                int curr = num;
                int cnt = 1;

                while(set.find(curr + 1) != set.end()) {
                    curr++;
                    cnt++;
                }

                maxi = max(maxi, cnt);
            }
        }

        return maxi;
    }
};