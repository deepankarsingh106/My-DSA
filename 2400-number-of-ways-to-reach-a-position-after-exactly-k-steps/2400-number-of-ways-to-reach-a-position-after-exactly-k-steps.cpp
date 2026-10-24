class Solution {
    int MOD = 1e9 + 7;
    int memo(int i,int j,int k,int st,int K,vector<vector<int>> &dp){
        if(k == 0){
            if(i == j){
                return 1;
            }
            else{
                return 0;
            }
        }
        int  idx = i - st + K;
        if(dp[idx][k] != -1){
            return dp[idx][k];
        }

        int left =  memo(i-1,j,k-1,st,K,dp);
        int right =  memo(i+1,j,k-1,st,K,dp);

        return dp[idx][k] = (left + right)% MOD;;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {

        int diff = endPos-startPos;

        if (abs(diff) > k || (k - abs(diff)) % 2 != 0) {
            return 0;
        }
        
        //vector<int> dp();
        
        vector<vector<int>> dp(2 * k + 1, vector<int>(k + 1, -1));
        
        return memo(startPos,endPos,k,startPos,k,dp);
    }
};