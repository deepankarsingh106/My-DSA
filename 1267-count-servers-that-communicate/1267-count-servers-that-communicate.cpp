class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n),col(m);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] && row[i] + col[j] > 2){
                    ++ans;
                }
            }
        }

        return ans;
    }
};