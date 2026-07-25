class Solution {
public:
    int maxProduct(int n) {
        vector<int> res;
        int cur =0;
        while(n > 0) {
            cur = n % 10;
            n = n/10;
            res.push_back(cur);
        }
        sort(res.begin(),res.end());
        reverse(res.begin(), res.end());
        return res[0]*res[1];
    }
};