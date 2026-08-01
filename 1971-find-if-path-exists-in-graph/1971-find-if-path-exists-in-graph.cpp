class Solution {
public:
    bool dfs(int src,int desti,vector<vector<int>> &adj,vector<int> &visited){

        if(src == desti)    return true;

        visited[src] = true;
        for(int i:adj[src]){
            if(!visited[i]){
                if(dfs(i,desti,adj,visited)){
                    return true;
                }
            }
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adj(n);

        for(int i = 0;i<edges.size();i++){

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        vector<int> visited(n);
        
        return dfs(source,destination,adj,visited);
    }
};