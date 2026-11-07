class Solution {

    bool SubsetSum(int idx,vector<int>&nums,int k,vector<vector<int>>&dp){

        if(k == 0)  return true;
        if(idx == 0)    return k == nums[0];

        if(dp[idx][k] != -1) return dp[idx][k];

        bool notaken = SubsetSum(idx-1,nums,k,dp);

        bool taken = false;

        if(k >= nums[idx]){
            taken = SubsetSum(idx-1,nums,k-nums[idx],dp);
        }

        return dp[idx][k] = notaken || taken;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totSum = 0;
        
        for(int i:nums) totSum += i;

        //odd sum can't be divided into 2 parts
        if(totSum % 2 != 0)    return false;
        
        vector<vector<int>>  dp(n+1,vector<int>(totSum+1,-1));
        int target = totSum/2,idx = n-1;
        
        return SubsetSum(idx,nums,target,dp);
    }
};