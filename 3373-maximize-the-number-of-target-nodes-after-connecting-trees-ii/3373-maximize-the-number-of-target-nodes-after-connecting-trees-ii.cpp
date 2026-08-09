class Solution {
private:
    void dfs(int i,int col,vector<vector<int>> &adj,vector<int> &col1){

        
        for(int j:adj[i]){
            if(col1[j] == -1){
                col1[j]=!col;
                dfs(j,!col,adj,col1);
            }
            
        }

    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
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

        int col=0;

        vector<int>col1(n+1,-1);
        vector<int> col2(m+1,-1);

        col1[0]=0;
        col2[0]=0;
        dfs(0,col,adj1,col1);
        dfs(0,col,adj2,col2);

        int cnt00=0,cnt01=0,cnt10=0,cnt11=0;
        for(int i=0;i<n+1;i++){
            if(col1[i]==0){
                cnt00++;
            }
            else{
                cnt01++;
            }
        }
        for(int i=0;i<m+1;i++){
            if(col2[i]==0){
                cnt10++;
            }
            else{
                cnt11++;
            }
        }
        vector<int> ans;

        for(int i = 0;i<n+1;i++){
            int colour = col1[i];
            int temp = max(cnt10,cnt11);
            if(col1[i] == 0)    temp += cnt00;
            else temp += cnt01;

            ans.push_back(temp);
        }

        return ans;
    }
};