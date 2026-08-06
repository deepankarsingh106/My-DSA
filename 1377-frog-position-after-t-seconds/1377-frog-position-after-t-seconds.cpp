class Solution {
    double ans = 0;
    void dfs(int i,double prob,vector<vector<int>> &adj,int t,vector<bool> &visited,int target){
        
        visited[i] = true; 

        int children = 0;
        for (int next : adj[i]) {
            if (!visited[next]) children++;
        }


        if(i == target){
            if(t == 0 || children == 0){
                ans = prob;
                return;
            }
        }

        if(t == 0){
            return;
        }
        
        //prob *= (1.0/children);

        for (int next : adj[i]) {
            if (!visited[next]) {
                dfs(next, prob/children, adj,t-1, visited, target);
            }
        }
        
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {

        int m = edges.size();
        
        //double ans = 0;

        vector<vector<int>> adj(n+1);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n+1,false);
        
        
        dfs(1,1.0,adj,t,visited,target);
        return ans;
    }
};