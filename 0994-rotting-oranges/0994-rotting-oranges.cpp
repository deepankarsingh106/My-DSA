class Solution {
private:
    bool isValid(int &x,int &y,int &n,int &m,vector<vector<int>>& grid){
        if(x >=0 && y >= 0 && x < n && y < m && grid[x][y] == 1){
            return true;
        }
        return false;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int m = grid[0].size();

        int minutes = 0;
        int total = 0;
        int cnt = 0;

        queue<pair<int,int>> q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    total++;
                }
                else if(grid[i][j]){
                    total++;
                }
            }
        }

        while(!q.empty()){

            int rotton = q.size();

            cnt += rotton;
            
            while(rotton--){
                int rox = q.front().first;
                int roy = q.front().second;
                q.pop();
        
                
                // down
                int x = rox + 1;
                int y = roy;
                if(isValid(x,y,n,m,grid)){
                    grid[x][y] = 2;
                    q.push({x,y});
                }
                
                // up
                x = rox - 1;
                y = roy;
                if(isValid(x,y,n,m,grid)){
                    grid[x][y] = 2;
                    q.push({x,y});
                }
                
                
                // left
                x = rox;
                y = roy-1;
                if(isValid(x,y,n,m,grid)){
                    grid[x][y] = 2;
                    q.push({x,y});
                }


                // right
                x = rox;
                y = roy+1;
                if(isValid(x,y,n,m,grid)){
                    grid[x][y] = 2;
                    q.push({x,y});
                }
            }
            if(!q.empty()){
                minutes++;
            }
        }
    return total == cnt? minutes:-1;}
};