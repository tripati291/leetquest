class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int m= edges.size() + 1;
        unordered_map<int,int> mp;
        vector<vector<int>> adj(m + 1);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        mp[1]=0;
        int maxi=0;
        queue<int> q;
        q.push(1);

        while(!q.empty()) {
            int node=q.front();
            q.pop();

            for(int idx: adj[node]) {
                if(!mp.count(idx)) {
                    mp[idx]= mp[node] + 1;
                    maxi= max(maxi, mp[idx]);
                    q.push(idx);
                }
            }
        }
        if(maxi==0) return 0;
        long long ans = 1;
        int MOD = 1e9 + 7;

        for (int i = 0; i < maxi - 1; i++) {
            ans = (ans * 2) % MOD;
        }
        return ans;
        
    }
};