class Solution {
public:
    bool isValid(string s) {
        int n= s.size();
        if (s[0] == ')' || s[0] == ']' || s[0] == '}') return false;
        if(s[n-1] == '(' || s[n-1] == '[' || s[n-1] == '{') return false;

        stack<char> st;
        for(int i=0; i<n; i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else {
                if(st.empty()) return false;
                if ((s[i]== ')' && st.top() == '(') || (s[i]== '}' && st.top() == '{') ||  (s[i]== ']' && st.top() == '[') ) {
                st.pop();
            } 
            else return false;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};