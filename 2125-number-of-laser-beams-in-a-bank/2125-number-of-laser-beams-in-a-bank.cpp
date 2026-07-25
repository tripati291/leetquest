class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m= bank.size();
        int n = bank[0].size();
        int sum=0;
        vector<int> store;
        for(int i=0; i<m; i++) {
            int sum=0;
            for(int j=0; j<n; j++) {
                if(bank[i][j]=='1') {
                    sum += 1;
                }
                else continue;
            }
            if(sum > 0) {
                store.push_back(sum);
            }
            else continue;
        }
        int ans=0;
        int i=0;
        if(store.size()==0) return 0;
        while(i < store.size() - 1) {
            ans += store[i]*store[i+1];
            i++;
        }
        return ans;
    }
};