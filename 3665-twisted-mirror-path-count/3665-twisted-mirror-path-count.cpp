class Solution {
    int memo(int i,int j,int dir,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        
        if(i == 0 && j == 0)    return 1;
        
        if(i < 0 || j < 0)  return 0;

        if(dp[i][j][dir] != -1)     return dp[i][j][dir];
        int ans = 0;
        if(grid[i][j] == 1) {
            if(dir == 0)
                ans = memo(i-1, j, 1, grid, dp);

            else
                ans = memo(i, j-1, 0, grid, dp);

        }
        else{
            int up = memo(i-1, j, 1, grid, dp);
            int left = memo(i, j-1, 0, grid, dp);
            ans = (up + left) % MOD;
        }
        return dp[i][j][dir] = ans;
    }
public:
    int MOD = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& grid) {
    
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(2,-1)));

        return memo(m-1,n-1,0,grid,dp);
    }
};