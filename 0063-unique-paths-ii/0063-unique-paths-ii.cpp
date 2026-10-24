class Solution {
     int memo(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &ob){
        
        if(i < 0 || j < 0 || ob[i][j] == 1){
            return 0;
        } 

        if(i == 0 && j == 0)    return 1;        

        if(dp[i][j] != -1)  return dp[i][j];

        int up = memo(i-1,j,dp,ob);
        int left = memo(i,j-1,dp,ob);

        return dp[i][j] = up+left; 
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m = ob.size();
        int n = ob[0].size();
        //if(m == 1 )
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return memo(m-1,n-1,dp,ob);
    }
};