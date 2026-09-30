class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int row=0;
        int col=0;
        int lr=m-1;
        int lc= n-1;
        while(row<=lr && col<=lc) {
            for(int i=col; i<=lc; i++) {
                ans.push_back(matrix[row][i]);
            }
            for(int i=row+1; i<=lr; i++) {
                ans.push_back(matrix[i][lc]);
            }
            for(int i= lc-1; i>=col; i--) {
                if(row==lr) break;
                ans.push_back(matrix[lr][i]);
            }
            for(int i= lr-1; i> row; i--) {
                if(col==lc) break;
                ans.push_back(matrix[i][col]);
            }
            row++;
            col++;
            lr--;
            lc--;
        }
        return ans;
    }
};