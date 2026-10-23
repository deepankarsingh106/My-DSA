class Solution {

    int f(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
        
        if(j < 0 || i < 0){
            return 1e9;
        }
        if(i == 0 && j == 0){
            return grid[0][0];
        }
        
        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }
        //up

        int up =  f(i-1,j,grid,dp);

        // left

        int left = f(i,j-1,grid,dp);

        return dp[i][j] = grid[i][j]+min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        return f(m-1,n-1,grid,dp);
    }
};