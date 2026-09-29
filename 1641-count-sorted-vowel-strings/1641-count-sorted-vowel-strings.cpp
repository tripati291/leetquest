class Solution {
public:
    int solve(int n, int start) {
        if (n == 0)
            return 1;
        int ans = 0;

        for (int i = start; i < 5; i++) {
            ans += solve(n - 1, i);
        }
        return ans;
    }

    int countVowelStrings(int n) {
        return solve(n, 0);
    }
};