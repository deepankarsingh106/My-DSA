class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<vector<int>> dis(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    visited[i][j] = true;
                }
            }
        }   

        while(!q.empty()){
            
            int x = q.front().first.first;
            int y = q.front().first.second;

            int step = q.front().second;
            dis[x][y] = step;
            q.pop();

            //down,left,right,up
            int x1[4] = {1,0,0,-1};
            int y1[4] = {0,-1,1,0};

            for(int i = 0;i<4;i++){
                int rox = x + x1[i];
                int roy = y + y1[i];
                if(rox >= 0 && roy >= 0 && rox < n && roy < m &&  visited[rox][roy] == false){
                    visited[rox][roy] = true;
                    q.push({{rox,roy},step+1});
                }
            }
        }
        return dis;

    }

};