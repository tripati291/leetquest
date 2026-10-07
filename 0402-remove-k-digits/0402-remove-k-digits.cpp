class Solution {
public:
    string removeKdigits(string num, int k) {
        string final= "";
        stack<char> st;
        for(int i=0; i< num.size(); i++) {
            while(!st.empty() && k>0 && st.top() > num[i] ) {
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
                final.push_back(st.top());
                st.pop();
            }
        }
        reverse(final.begin(), final.end());
        int j=0;
        while(j< final.size() && final[j]=='0') {
            j++;
        }
        final = final.substr(j);
        return final.empty() ? "0" : final;

    }
};