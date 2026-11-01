class Solution {
    int MOD = 1e9 + 7;
    int solve(int i,int j,vector<string> &board,unordered_map<int,int> &mp,vector<vector<int>> &dp,vector<vector<int>> &w){

        int n = board.size();

        if(i < 0 || j < 0 || board[i][j] == 'X'){
            return -1e9;
        }
        
        if(i == 0 && j == 0){
            w[i][j] = 1;
            return 0;
        }
        if(dp[i][j] != -1)  return dp[i][j];

        int up = solve(i-1,j,board,mp,dp,w);
        int ld = solve(i-1,j-1,board,mp,dp,w);
        int left = solve(i,j-1,board,mp,dp,w);

        int ans = max({up,left,ld});

        if(ans == -1e9) return dp[i][j] = -1e9;
        
        int c = 0;
    
        if(up == ans){
            c = (c + w[i-1][j]) % MOD; 
        }
        if(ld == ans){
            c = (c + w[i-1][j-1]) % MOD;
        }
        if(left == ans){
            c = (c + w[i][j-1]) % MOD;
        }
        w[i][j] = c;
        if(board[i][j] != 'S' && board[i][j] != 'E')  ans += (board[i][j] - '0');
        
        return dp[i][j] = ans;
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        
        int n = board.size();

        unordered_map<int,int> mp;
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<vector<int>> ways(n,vector<int>(n,0));
        
        int ans = solve(n-1,n-1,board,mp,dp,ways);
        if(ans < 0) return {0,0};
        return {ans,ways[n-1][n-1]};
    }
};