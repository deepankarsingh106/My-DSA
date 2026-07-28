class Solution {
private:
    void dfs(int i,unordered_map<int,vector<int>> &adj,
            unordered_map<int,bool> &visited){
                visited[i]  = true;

                for(int j:adj[i]){
                    if(!visited[j]){
                        dfs(j,adj,visited);
                    }
                }
            }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int,vector<int>> adj;
        unordered_map<int,bool>visited;
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int count = 0;
        for(int i = 1;i<=n;i++){
            if(!visited[i]){
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
};