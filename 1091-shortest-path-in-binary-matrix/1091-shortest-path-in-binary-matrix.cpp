class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m  = grid[0].size();

        //vector<vector<bool>> visited(n,vector<bool>(m,false));

        queue<pair<int,pair<int,int>>> q;
        if(grid[0][0] != 0 || grid[n-1][m-1] != 0){
            return -1;
        }
        q.push({1,{0,0}});
        grid[0][0] = 1;
        while(!q.empty()){
            
            int path = q.front().first;
            int u = q.front().second.first;
            int v = q.front().second.second;

            q.pop();

            if(u == n-1 && v == m-1){
                return path;
            }
            // down,down-right,right,up-right,up,left-up,left,left-down
            int x1[8] = {1,1,0,-1,-1,-1,0,1};
            int y1[8] = {0,1,1,1,0,-1,-1,-1};

            for(int i = 0;i<8;i++){
                int rx = u + x1[i];
                int ry = v + y1[i];

                if(rx >= 0 && ry >= 0 && rx < n && ry < m && grid[rx][ry] == 0){
                    grid[rx][ry] = 1;
                    q.push({path+1,{rx,ry}});
                }
            }      
        }
        return -1;
    }
};