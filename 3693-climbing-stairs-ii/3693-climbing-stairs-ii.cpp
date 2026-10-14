class Solution {
public:

    int solve(int n, vector<int> &dp,vector<int> &cost){

        if(n <= 0){
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }
        int second = INT_MAX,third = INT_MAX;
        int first = solve(n-1,dp,cost) + cost[n-1]+1;
        if(n > 1)   second = solve(n-2,dp,cost) + cost[n-1]+4;
        if(n > 2)   third = solve(n-3,dp,cost) + cost[n-1]+9;

        dp[n] = min(first,min(second,third));

        return dp[n];
    }
    int climbStairs(int n, vector<int>& costs) {
        
        vector<int> dp(n+1,-1);
        
        return solve(n,dp,costs);
    }
};