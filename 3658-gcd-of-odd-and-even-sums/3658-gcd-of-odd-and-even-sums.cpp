class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        if(n==1) return 1;
        int x = ((2*n)*(2*n + 1))/2;
        int odd = x/2 - n/2 ;
        int even = x - odd;
        int ans=0;
        int maxi=0;
        for(int i=1; i<= odd/2 ; i++) {
            if(odd%i ==0 && even%i ==0) {
                 maxi = i;
            }
            ans = max(ans , maxi);
        }
        return ans;
    }
};