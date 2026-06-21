class Solution {
public:
    int f(int i, vector<int>& costs, int coins ) {
        if(i == costs.size()) return 0;
        if(coins>= costs[i]) {
            return 1 + f(i+1, costs, coins - costs[i]);
        }
        else return 0;
    }
    int maxIceCream(vector<int>& costs, int coins) {
        int n= costs.size();
        sort(costs.begin(),costs.end());
        return f(0, costs, coins);    
    }
};