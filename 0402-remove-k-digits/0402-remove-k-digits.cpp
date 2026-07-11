class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans= "";
        stack<char> st;
        for(int i=0; i< num.size(); i++) {
            while(!st.empty() && st.top() > num[i] && k>0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty()) {
            if(k>0) {
                st.pop();
                k--;
            }
            else {
                ans.push_back(st.top());
                st.pop();
            }
        }
        reverse(ans.begin(), ans.end());
        int j=0;
        while(j< ans.size() && ans[j]=='0') {
            j++;
        }
        ans = ans.substr(j);
        return ans.empty() ? "0" : ans;

    }
};