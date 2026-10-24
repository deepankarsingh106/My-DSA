class Solution {

    int f(int i,int j,vector<vector<int>>&t,vector<vector<int>>& dp){

        if(i == 0)  return t[0][0];

        if(j < 0 || j >= t[i].size()){
            return 1e9;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up = f(i-1,j,t,dp);
        int prev = f(i-1,j-1,t,dp);

        return dp[i][j] = t[i][j] + min(up,prev);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        int ans = INT_MAX;

        for(int i = 0;i<triangle[n-1].size();i++){
            ans = min(ans,f(n-1,i,triangle,dp));
        }

        return ans;
    }
};