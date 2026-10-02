class Solution {

int solve(vector<int>&nums,vector<int>&dp,int n){

    if(n == 0){
        return nums[0];
    }

    if(n < 0){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int incl = solve(nums,dp,n-2) + nums[n];
    int excl = solve(nums,dp,n-1);

    dp[n] = max(incl,excl);
    
    return dp[n];
}

int sol(vector<int> &a){
    int n = a.size();

    vector<int>dp(n+1,-1);

    return solve(a,dp,n-1);
}
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        if(n == 2){
            return max(nums[0],nums[1]);
        }
        
        vector<int> a(nums.begin(),nums.end()-1);
        
        vector<int> b(nums.begin()+1,nums.end());
        //bool flag = 0;
        
        int ans = max(sol(a),sol(b));
        
        return ans;
    }
};