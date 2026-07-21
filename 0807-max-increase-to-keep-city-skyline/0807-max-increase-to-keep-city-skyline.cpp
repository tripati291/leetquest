class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n= grid.size();
        int oldsum=0;
        for(int i=0; i<n ;i++) {
            for(int j=0; j<n; j++) {
                oldsum += grid[i][j];
            }
        }
        vector<int> rows(n, 0);
        vector<int> cols(n, 0);
        for(int i=0; i<n; i++) {
            int maxi=0;
            for(int j=0; j<n; j++) {
                maxi= max(maxi, grid[i][j]);
            }
            rows[i] = maxi;
        }
        for(int j=0; j<n; j++) {
            int maxii=0;
            for(int i=0; i<n; i++) {
                maxii= max(maxii, grid[i][j]);
            }
            cols[j] = maxii;
        }
        for(int i=0; i<n ;i++) {
            for(int j=0; j<n; j++) {
                grid[i][j] = min(rows[i] , cols[j]);
            }
        } 
        int sum=0;
        for(int i=0; i<n ;i++) {
            for(int j=0; j<n; j++) {
                sum += grid[i][j];
            }
        }
        return sum - oldsum ;            
    }
};