class Solution {

    int f(int row,int col,vector<vector<int>> &matrix,vector<vector<int>> &dp){

        int n = matrix[0].size();

        if(col < 0 || col >= n){
            return 1e9;
        }

        if(row == 0){
            return matrix[row][col];
        }

        
        if(dp[row][col] != INT_MAX){
            return dp[row][col];
        }
        
        // leftdiagonally
        int ld = f(row-1,col-1,matrix,dp);
        // rightdiagonally
        int up = f(row-1,col+1,matrix,dp);
        // upward
        int rd = f(row-1,col,matrix,dp);

        int ans = min({ld,up,rd});

        return dp[row][col] = matrix[row][col] + ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        
        int ans = INT_MAX;

        for(int j = 0;j<n;j++){
            ans = min(ans,f(n-1,j,matrix,dp));
        }
        
        return ans;
    }
};