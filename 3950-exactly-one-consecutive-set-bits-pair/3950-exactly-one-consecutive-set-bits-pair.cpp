class Solution {
public:
    bool consecutiveSetBits(int n) {
        if(n==0) return false;
        string s="";

        while(n>0) {
            s= char('0' + (n%2)) + s;
            n= n/2;
        }
        vector<int> ans;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='1') {
                ans.push_back(i);
            }
        }
        int cnt=0;
        for(int i=0; i<ans.size()-1; i++) {
            if(ans[i+1]-ans[i]==1) cnt++;
            else continue;
        }
        if(cnt==1) return true;
        else return false;
        
    }
};