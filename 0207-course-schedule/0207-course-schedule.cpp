class Solution {
private:
    bool dfs(int i,unordered_map<int,vector<int>> &adj,
             unordered_map<int,bool> &visited,
             unordered_map<int,bool> &dfscalled){
            visited[i] = true;
            dfscalled[i] = true;
            for(int j:adj[i]){
                if(!visited[j] && !dfscalled[j]){
                    if(!dfs(j,adj,visited,dfscalled)){
                        return false;
                    }
                }else if(dfscalled[j] && visited[j]){
                    return false;
                }
            }         
            dfscalled[i] = false;   
            return true;
        }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = prerequisites.size();

        unordered_map<int,vector<int>>adj;

        for(int i = 0;i<n;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfscalled;
        
        for(int i = 0;i<numCourses;i++){
            if(!visited[i]){
                bool ans = dfs(i,adj,visited,dfscalled);
                if(!ans) return false;
            }
        }
    return true;}
};