class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        reverse(piles.begin(), piles.end());
        int n = (piles.size())/3;
        int sum=0;
        for(int i=1; i< 2*n; i += 2) {
            sum += piles[i];
        }
        return sum;
    }
};