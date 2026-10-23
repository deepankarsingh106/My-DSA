class Solution {
    int f(int row,int col,vector<vector<int>> &matrix,vector<vector<int>> &dp){

        int n = matrix[0].size();

        if(row == 0){
            int mini = 101;
            for(int i = 0;i<n;i++){
                if(i != col)    mini = min(mini,matrix[0][i]);
            }
            return mini;
        }

        
        if(dp[row][col] != INT_MAX){
            return dp[row][col];
        }
        int mini = 1e9;
        for(int i = 0;i<n;i++){
            if(i != col){
                int points = matrix[row][i] + f(row-1,i,matrix,dp);
                mini = min(mini,points);
            }
        }

        return dp[row][col] = mini;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(n == 1 && m == 1)    return matrix[0][0];
        
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        
        int ans = INT_MAX;

        for(int j = 0;j<n;j++){
            ans = min(ans,f(n-1,j,matrix,dp));
        }
        
        return ans;
    }
};