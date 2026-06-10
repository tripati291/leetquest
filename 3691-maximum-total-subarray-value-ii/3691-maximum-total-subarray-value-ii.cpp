class Solution {
public:
    using ll = long long;
    struct Node {
        ll val;
        int l, r;
        bool operator<(const Node& other) const {
            return val < other.val;
        }
    };
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> lg(n + 1);
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }
        int K = lg[n] + 1;
        vector<vector<int>> mx(K, vector<int>(n));
        vector<vector<int>> mn(K, vector<int>(n));
        for (int i = 0; i < n; i++) {
            mx[0][i] = mn[0][i] = nums[i];
        }
        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                mx[j][i] = max(mx[j - 1][i],
                               mx[j - 1][i + (1 << (j - 1))]);

                mn[j][i] = min(mn[j - 1][i],
                               mn[j - 1][i + (1 << (j - 1))]);
            }
        }
        auto value = [&](int l, int r) -> ll {
            int len = r - l + 1;
            int p = lg[len];
            int maxi = max(mx[p][l],
                           mx[p][r - (1 << p) + 1]);

            int mini = min(mn[p][l],
                           mn[p][r - (1 << p) + 1]);

            return 1LL * maxi - mini;
        };
        priority_queue<Node> pq;

        for (int l = 0; l < n; l++) {
            pq.push({value(l, n - 1), l, n - 1});
        }

        ll ans = 0;

        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();
            ans += val;
            if (r > l) {
                pq.push({value(l, r - 1), l, r - 1});
            }
        }
        return ans;
    }
};