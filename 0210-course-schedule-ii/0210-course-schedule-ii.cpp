class Solution {
private:
    bool dfs(int i,unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &visited,
                unordered_map<int,bool> &dfscalled,vector<int>&ans){
        
        visited[i] = true;

        dfscalled[i] = true;

        for(int j:adj[i]){
            if(!visited[j] && !dfscalled[j]){
                if(!dfs(j,adj,visited,dfscalled,ans)){
                    return false;
                }
            }
            else if(dfscalled[j]){
                return false;
            }
        }
        
        ans.push_back(i);
        
        dfscalled[i] = false;

        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = prerequisites.size();

        vector<int> ans;

        if(n == 0){
            for(int i = 0;i<numCourses;i++){
                ans.push_back(i);
            }
            return ans;
        }
        
        unordered_map<int,vector<int>> adj;
        
        for(int i = 0;i<n;i++){
                int u = prerequisites[i][0];
                int v = prerequisites[i][1];
                adj[v].push_back(u);
        }

        unordered_map<int,bool> visited;
        
        unordered_map<int,bool> dfscalled;
        
        for(int i = 0;i<numCourses;i++){
            if(!visited[i]){
                if(!dfs(i,adj,visited,dfscalled,ans)){
                    return {};
                }
            }
        }
        reverse(ans.begin(),ans.end());

    return ans;}
};