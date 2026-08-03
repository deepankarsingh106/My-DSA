class Solution {
private:
    bool dfs(int i,int col,vector<int>&color,vector<vector<int>>& graph){
        color[i] = col;

        for(int j:graph[i]){
            if(color[j] == -1){
                if(!dfs(j,!col,color,graph)){
                    return false;
                }
            }
            else if(color[j] == col){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int v = graph.size();
        
        vector<int>color(v,-1);

        int col = 0;
        
        for(int i = 0;i<v;i++){
            if(color[i] == -1 && !dfs(i,col,color,graph)){
                return false;
            }
        }
    return true;
    }
};