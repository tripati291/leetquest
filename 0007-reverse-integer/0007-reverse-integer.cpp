class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        if (x == INT_MIN) return 0;
        
        int y =x;
        x = abs(x);
        string a;
        while (x > 0) {
            a.push_back((x % 10) + '0');
            x /= 10;
        }
        long long ans = stoll(a);   

        if (ans > INT_MAX) return 0;
        return y<0 ? -ans : ans ;
    }
};