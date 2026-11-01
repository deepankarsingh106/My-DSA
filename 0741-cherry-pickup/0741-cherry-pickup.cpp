class Solution {

    int memo(int r1,int c1,int c2,vector<vector<int>> &grid,                vector<vector<vector<int>>> &dp){
            
            int n = grid.size();

            // MANHATTAN DISTANCE of these 2 points are same from origin
            // r1 - 0 + c1 - 0 = r2 - 0 + c2 - 0;
            int r2 = r1 + c1 - c2;
            
                if(r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0 ||
    r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
    grid[r1][c1] == -1 || grid[r2][c2] == -1) {
        return -1e9;
    }

            if(r1 == n-1 && c1 == n-1)  return grid[r1][c1];

            if(dp[r1][c1][c2] != INT_MIN)    return dp[r1][c1][c2]; 

            int ans = grid[r1][c1];

            if(c1 != c2)    ans += grid[r2][c2];

            // right , right         
            // right , down
            int temp = max(memo(r1,c1 + 1,c2 + 1,grid,dp),memo(r1,c1+1,c2,grid,dp));        
            // down , right 
            temp = max(temp,memo(r1 + 1,c1,c2 + 1,grid,dp));        
            // down , down
            temp = max(temp,memo(r1+1,c1,c2,grid,dp));

            ans += temp;
            
            return dp[r1][c1][c2] = ans; 
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,INT_MIN)));

        int ans = memo(0,0,0,grid,dp);
        return max(0,ans);
    }
};