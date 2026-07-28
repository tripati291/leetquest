class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        if (n % 2 == 0) {
            string temp = s.substr(0, n / 2);
            sort(temp.begin(), temp.end());

            string re = temp;
            reverse(re.begin(), re.end());

            return temp + re;
        }
        else {
            string temp = s.substr(0, n / 2);
            sort(temp.begin(), temp.end());

            string re = temp;
            reverse(re.begin(), re.end());

            return temp + string(1, s[n / 2]) + re;
        }
    }
};