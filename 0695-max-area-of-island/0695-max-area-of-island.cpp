class Solution {
    int maxarea = 0;
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid,int &area){

        area += 1;
        maxarea = max(maxarea,area);

        grid[i][j] = 0;

        int x1[4] = {1,0,0,-1};
        int y1[4] = {0,-1,1,0};

        for(int k = 0;k<4;k++){
            int u = i + x1[k];
            int v = j + y1[k];

            if(u >= 0 && v >= 0 && u < n && v < m && grid[u][v]){
                dfs(u,v,n,m,grid,area);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        int m = grid[0].size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] != 0){
                    int area = 0;
                    grid[i][j] = 0;
                    dfs(i,j,n,m,grid,area);
                }
            }
        }
    return maxarea;}
};