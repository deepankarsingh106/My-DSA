class Solution {
private:
    void bfs(int &x,int &y,int &n,int &m,vector<vector<char>> &grid){

        queue<pair<int,int>>q;

        q.push({x,y});
        grid[x][y] = '0';

        int x1[4]={0,0,-1,1};
        int y1[4]={-1,1,0,0};

        while(!q.empty()){

            int x11 = q.front().first;
            int y11 = q.front().second;
            q.pop();
            
            
            
            //left,right,up,down
            

            for(int i = 0;i<4;i++){
                int rx = x11 + x1[i];
                int ry = y11 + y1[i];
                if(rx >= 0 && rx < n && ry >= 0 && ry < m && grid[rx][ry] == '1'){
                   grid[rx][ry] = '0';
                   q.push({rx,ry});
                }
            } 
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                   count++;
                   bfs(i,j,n,m,grid);
                }
            }
        }
    return count;}
};