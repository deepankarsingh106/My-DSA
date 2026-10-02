class Solution {

private:
    int solve(int x,vector<int> &dp,vector<int>& nums){


        int n = nums.size();

        for(int i = 1;i<=x;i++){
            for(int j = 0;j<n;j++){
                if(i-nums[j]>=0 && dp[i-nums[j]] != INT_MAX){
                    dp[i] = min(dp[i],1+dp[i-nums[j]]);
                }
            }
        }


        return dp[x];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        int ans = solve(amount,dp,coins);
        if(ans == INT_MAX)  return -1;
        return ans;
    }
};