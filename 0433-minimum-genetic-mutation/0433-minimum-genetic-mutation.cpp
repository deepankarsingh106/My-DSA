class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        unordered_set<string> st(bank.begin(),bank.end());
        
        unordered_map<string,bool> visited;
        
        if(!st.count(endGene)){
            return -1;
        }
        
        queue<pair<string,int>> q;
        
        visited[startGene] = true;
        
        q.push({startGene,0});

        string dir = "ACGT";
        
        while(!q.empty()){

            string code = q.front().first;
        
            int moves = q.front().second;
            q.pop();

            if(code == endGene){
                return moves;
            }

            string temp = code;
            
            for(int i = 0;i<temp.size();i++){
            
                char original = temp[i];
            
                for(int j = 0;j<4;j++){
            
                    temp[i] = dir[j];
            
                    if(original == temp[i] || st.count(temp) == 0) continue;
            
                    if(st.count(temp) && !visited[temp]){
            
                        visited[temp] = true;
                        q.push({temp,moves+1});
                    }
                }
                temp = code;
            }


        }

        return -1;
    }
};