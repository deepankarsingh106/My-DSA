class Solution {
private:
    int solve(int i,int n,vector<int>&dp,vector<int>&nums){
        
        if(i >= n)    return 0;

        if(dp[i] != -1){
            return dp[i];
        }

        int val = nums[i];

        int currsum = 0;

        int idx = i;

        while(idx < n && val == nums[idx]){
            currsum += nums[idx];
            idx++;
        }

        int next = val + 1;
        
        while(idx < n && next == nums[idx]){
            idx++;
        }

        int take = currsum + solve(idx,n,dp,nums);

        int skpidx = i;
        
        while(skpidx < n && nums[skpidx] == val)  skpidx++;

        int skip = solve(skpidx,n,dp,nums);
    
        return dp[i] = max(take,skip);
    }
public:
    int deleteAndEarn(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(),nums.end());
        
        vector<int>dp(n+1,-1);

        return solve(0,n,dp,nums);
    }
};