class Solution {
private:
    void dfs(int k,vector<vector<int>>&adj,vector<bool> &visited){
        
        for(int j:adj[k]){
            if(!visited[j]){
                visited[j] = true;
                dfs(j,adj,visited);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        int m = invocations.size();

        vector<vector<int>> adj(n);

        for(int i = 0;i<m;i++){
            int u = invocations[i][0];
            int v = invocations[i][1];
            adj[u].push_back(v);
        }
        
        vector<bool> visited(n,false);
        
        visited[k] = true;
        
        dfs(k,adj,visited);

        for(int i = 0;i<m;i++){
            int u = invocations[i][0];
            int v = invocations[i][1];
            if(!visited[u] && visited[v]){
                vector<int>ans;
                for(int i = 0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }            
        }
        vector<int>ans;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                ans.push_back(i);
            }
        }
        
        return ans; 
    }
};