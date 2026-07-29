class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>>q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){

                if(board[i][j] == 'O' && (i == 0 || i == n-1  || j == 0 || j == m-1)){
                    q.push({i,j});
                    board[i][j] = '#';
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            //down,left,right,up
            int dx[4] = {1,0,0,-1};
            int dy[4] = {0,-1,1,0};

            for(int i = 0;i<4;i++){
                int zx = x + dx[i];
                int zy = y + dy[i];

                if(zx >= 0 && zx < n && zy >= 0 && zy < m && board[zx][zy] == 'O'){
                    board[zx][zy] = '#';
                    q.push({zx,zy});
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){

                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};