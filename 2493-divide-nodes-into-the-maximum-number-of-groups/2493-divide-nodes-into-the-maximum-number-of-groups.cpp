class Solution {
private:
     void dfs(int node, unordered_map<int,vector<int>> &adj,
             vector<int> &component, vector<bool> &vis){

        vis[node] = true;
        component.push_back(node);

        for(int nei : adj[node]){
            if(!vis[nei]){
                dfs(nei, adj, component, vis);
            }
        }
    }
    int bfs(int u,unordered_map<int,vector<int>> &adj,int n){

        vector<int> grpassign(n + 1, 0);
        
        queue<pair<int,int>> q;

        int grpsize = 1;
        
        q.push({1,u});
        
        grpassign[u] = 1;
        
        while(!q.empty()){

            int grp = q.front().first;
            int node = q.front().second;
            q.pop();
            for(int j:adj[node]){

                if(!grpassign[j]){
                    grpassign[j] = grp+1;
                    grpsize = max(grpsize,grpassign[j]);
                    q.push({grp+1,j});
                }
                else if(abs(grpassign[j]-grp) != 1){
                    return -1;
                }
            }
        }
        return grpsize;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        
        int m = edges.size();

        int groupsize = 0;

        unordered_map<int,vector<int>> adj;
        
        for(int i = 0;i<m;i++){
        
            int u = edges[i][0];
            
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        } 

        vector<bool> visited(n+1,false);
        
        for(int i  = 1;i<=n;i++){
            
            if(visited[i])  continue;

            vector<int> components;

            dfs(i,adj,components,visited);

            int best = 0;
            for(int node:components){
                
                int grp = bfs(node,adj,n);
                
                if(grp == -1)  return -1;
            
                best = max(grp,best);
            }
            groupsize += best;
            
        }
        return groupsize;
    }
};