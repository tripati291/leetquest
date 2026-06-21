class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int a=0, maxi=0;
        unordered_map<int, int> mp;
        for(int i=0; i < fruits.size(); i++) {
            mp[fruits[i]]++;

            while(mp.size() > 2) {
                mp[fruits[a]]--;
                if (mp[fruits[a]]==0) {
                    mp.erase(fruits[a]);
                }
                a++;
            }
            maxi = max(maxi, i-a+1);
        }
        return maxi;    
    }
};