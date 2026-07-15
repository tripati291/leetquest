class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n= nums.size();
        vector<int> old;
        old = nums;
        vector<int> nya;
        while(old.size()>=1) {
            for(int i=0 ; i< old.size() -1 ; i++ ) {
                nya.push_back((old[i] + old[i+1])%10);
            }
            old= nya;
            nya= vector<int> ();
        }
        return old[0];
    }
};