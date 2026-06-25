class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        vector<int> dup = score;
        sort(dup.begin(), dup.end());

        unordered_map<int,int> rank;

        for(int i = 0; i < n; i++) {
            rank[dup[i]] = n - i;
        }

        vector<string> ans;

        for(int i = 0; i < n; i++) {
            int r = rank[score[i]];

            if(r == 1)
                ans.push_back("Gold Medal");
            else if(r == 2)
                ans.push_back("Silver Medal");
            else if(r == 3)
                ans.push_back("Bronze Medal");
            else
                ans.push_back(to_string(r));
        }

        return ans;
    }
}; 
