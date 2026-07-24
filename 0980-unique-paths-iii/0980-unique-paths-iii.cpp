class Solution {
private:
    bool isSafe(int row,int col,vector<vector<int>>& grid,
        vector<vector<bool>> &visited,int n,int m){
            if(row >= 0 && row < n && col >= 0 && col < m){
                if(grid[row][col] != -1 && visited[row][col] != true){
                    return true;
                }
            }
        return false;
    }
    // bool isVisited(vector<vector<int>>& grid,vector<vector<bool>> &visited){
    //     for(int i = 0;i<visited.size();i++){
    //         for(int j = 0;j<visited[i].size();j++){
    //             if(grid[i][j] != -1 && visited[i][j] == false){
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    void solve(vector<vector<int>>& grid,int row,int col,int n,int m,
        vector<vector<bool>> &visited,int cells,int &path){
            if(grid[row][col] == 2 && cells == 1){
                path++;
                return;
            }
            cells--;
            visited[row][col] = true;
            //D
            if(isSafe(row+1,col,grid,visited,n,m)){
                solve(grid,row+1,col,n,m,visited,cells,path);
            }
            //L
            if(isSafe(row,col-1,grid,visited,n,m)){
                solve(grid,row,col-1,n,m,visited,cells,path);
            }

            //R
            if(isSafe(row,col+1,grid,visited,n,m)){
                solve(grid,row,col+1,n,m,visited,cells,path);
            }

            //U
            if(isSafe(row-1,col,grid,visited,n,m)){
                solve(grid,row-1,col,n,m,visited,cells,path);
            }
            cells++;
            visited[row][col] = false;
        }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        int path = 0;
        int row = -1,col = -1;

        int cells = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] != -1){
                    if(grid[i][j] == 1 && row == -1 && col == -1){
                        row = i;col = j;
                    }
                    cells++;
                }
            }
        }
        solve(grid,row,col,n,m,visited,cells,path);
        return path;
    }
};