class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        sort(candyType.begin(), candyType.end());        
        int i = 0;
        int j = 1;
        int count = 1;
        while(j < n){
            if(candyType[i] == candyType[j]) j++;
            else{
                count++;
                i = j;
                j++;
            }
        }

        if(count > n/2) return n/2;
        else return count; 
    }
};