class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n = grid.size();

        int m = grid[0].size();
        
        map<vector<int>,int> mp;

        for(int i = 0;i<n;i++){
            mp[grid[i]]++;
        }

        int count = 0;
        for(int j = 0;j<m;j++){
            
            vector<int>temp;
            
            for(int i = 0;i<n;i++){
                temp.push_back(grid[i][j]);
            }

            count += mp[temp];
        
        }
        return count;
    }
};