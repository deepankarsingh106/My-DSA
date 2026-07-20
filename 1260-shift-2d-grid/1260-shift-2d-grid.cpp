class Solution {
private:
    void reverseArray(vector<int>&temp,int i,int j){
        while(i < j){
            swap(temp[i++],temp[j--]);
        }
    }
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        if( n == 1 && m == 1 || k == 0)   return grid; 
        vector<int>temp;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                temp.push_back(grid[i][j]);
            }
        }
        int size = temp.size();
        k = k%size;
        // for right rotation 
        reverseArray(temp,0,size-1);
        reverseArray(temp,0,k-1);
        reverseArray(temp,k,size-1);
        int l = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(l < size){
                    grid[i][j] = temp[l];
                    l++;
                }
            }
        }

        return grid;
    }
};