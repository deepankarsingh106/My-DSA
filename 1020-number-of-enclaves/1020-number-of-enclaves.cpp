class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
         
        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    if(i == 0 || j == 0 || i == n-1 || j == m-1){
                        q.push({i,j});
                        grid[i][j] = -1;
                    }    
                }
            }
        }

        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            //down,left,right,up
            int xd[4] = {1,0,0,-1};
            int yd[4] = {0,-1,1,0};

            for(int i = 0;i<4;i++){

                int rox = x + xd[i];
                int roy = y + yd[i];

                if(rox >= 0 && roy >= 0 && rox < n && roy < m && grid[rox][roy] == 1){
                    q.push({rox,roy});
                    grid[rox][roy] = -1;
                }
            }
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){   
                    count++;
                }
            }
        }
    return count;
        
    }
};