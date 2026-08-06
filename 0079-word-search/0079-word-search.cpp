class Solution {
    bool dfs(int i,int j,int &n,int &m,vector<vector<char>>& board,int k,string &w){
        if(k == w.size()-1){
            return true;
        }

        if(board[i][j] != w[k]) return false;
        
        char temp = board[i][j];
        board[i][j] = '#';
        int x1[4] = {1,0,0,-1};
        int y1[4] = {0,1,-1,0};

        for(int d = 0;d<4;d++){
            int u = i + x1[d];
            int v = j + y1[d];
            if(u >= 0 && v >= 0 && u < n && v < m){
                if(board[u][v] == w[k+1]){
                    if(dfs(u,v,n,m,board,k+1,w)){
                        return true;
                    }
                }

            }
        }
        board[i][j] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(dfs(i,j,n,m,board,0,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};