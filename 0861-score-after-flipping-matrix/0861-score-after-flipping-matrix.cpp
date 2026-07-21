class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n= grid[0].size();
        for(int i=0; i< m; i++) {
            if(grid[i][0] == 0) {
                for(int j=0; j<n; j++) {
                    if(grid[i][j]==0) {
                        grid[i][j] = 1;
                    }
                    else {
                        grid[i][j] = 0;
                    }
                }
            }
        }
        for(int j=1; j<n; j++) {
            int cnt=0;
            for(int i=0; i<m; i++) {
                if(grid[i][j]==0) cnt++;
            }
            if(cnt > m/2) {
                for(int i=0; i<m; i++) {
                    if(grid[i][j]==0) {
                        grid[i][j] = 1;
                    }
                    else {
                        grid[i][j] = 0;
                    }
                }
            }
        }
        int ans=0;
        for(int j=0; j<n; j++) {
            int c=0;
            for(int i=0; i<m; i++) {
                if(grid[i][j]==1) c++;
            }
            ans += c* pow(2, n-j-1);
        }
        return ans;
    }
};