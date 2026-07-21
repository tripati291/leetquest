class Solution {
public:
    void f(int k, string& s) {
        if( s.size() >= k) return ;
        string temp(s.size(), ' ');
        for(int i=0; i<s.size(); i++) {
            temp[i] = char(s[i] == 'z' ? 'a' : s[i] + 1) ;
        }
        s += temp;
        f(k, s);
    }
    char kthCharacter(int k) {
        string s = "a";
        f(k, s);
        return s[k-1];
    }
};