class Solution {
    pair<int,int> bfs(int src,vector<vector<int>> &adj){
        int n = adj.size();
        vector<int> dist(n,-1);

        queue<int>q;
        q.push(src);
        dist[src] = 0;
        int farthestNode = src;
        while(!q.empty()){

            int node = q.front();q.pop();

            for(int j:adj[node]){
                if(dist[j] == -1){
                    dist[j] = dist[node] + 1;
                    q.push(j);

                    if(dist[j] > dist[farthestNode]){
                        farthestNode = j;
                    }
                }
            }
        }
        return {farthestNode,dist[farthestNode]};
}
    int diameter(vector<vector<int>> &adj){
        auto p1 = bfs(0,adj);
        auto p2 = bfs(p1.first,adj);

        return p2.second;
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        int n = edges1.size();
        int m = edges2.size();

        // first graph

        vector<vector<int>> adj1(n+1);
        //second graph
        vector<vector<int>> adj2(m+1);

        for(int i = 0;i<n;i++){
            int u = edges1[i][0];
            int v = edges1[i][1];

            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        
        for(int i = 0;i<m;i++){
            int u = edges2[i][0];
            int v = edges2[i][1];

            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        int d1 = diameter(adj1);
        int d2 = diameter(adj2);
        

        int ans = max(d1,max(d2,((d1+1)/2 +(d2+1)/2 + 1)));
        return ans;
    }
};