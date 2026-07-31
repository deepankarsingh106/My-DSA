class Solution {
private:
    void bfs(int &x,int&y,int &n,int &m,vector<vector<char>>& board){

        board[x][y] = '.';

        queue<pair<int,int>> q;
        
        q.push({x,y});
        
        while(!q.empty()){

            int x11 = q.front().first;
            int y11 = q.front().second;

            board[x11][y11] = '.';

            q.pop();

            int x1[4] = {1,0,0,-1};
            int y1[4] = {0,-1,1,0};
            
            for(int i=0;i<4;i++){

                int rx = x11 + x1[i];
                int ry = y11 + y1[i];

                if(rx >= 0 && ry >= 0 && rx < n && ry < m && board[rx][ry] == 'X'){
                    q.push({rx,ry});
                }
            }
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        
        int n = board.size();
        
        int m = board[0].size();
        
        queue<pair<int,int>>q;
        
        int cnt = 0;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == 'X'){
                    cnt++;
                    bfs(i,j,n,m,board);
                }
            }
        }

        return cnt;
    }
};