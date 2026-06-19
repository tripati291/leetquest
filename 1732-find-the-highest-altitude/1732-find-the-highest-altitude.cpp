class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int maxi = 0;

        for (int i = 0; i <= n; i++) {
            int x = 0;

            for (int j = 0; j < i; j++) {
                x += gain[j];
            }

            maxi = max(maxi, x);
        }
        return maxi;
    }
};