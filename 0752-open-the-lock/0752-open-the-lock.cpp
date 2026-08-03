class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        set<string> st(deadends.begin(),deadends.end());
        if(st.count("0000") > 0){
            return -1;
        }
        unordered_map<string,bool> visited;
        queue<pair<string,int>>q;
        
        q.push({"0000",0});
        
        visited["0000"] = true;
         while(!q.empty()){
        
            string code = q.front().first;

            int moves = q.front().second;
            
            q.pop();
            
            if(code == target)  return moves;
            
            string temp = code;
            
            for(int i = 0;i<4;i++){

                string up = code,down = code;
                up[i] = (up[i] == '9')? '0':up[i]+1;
                down[i] = (down[i] == '0')? '9':down[i]-1;

                if(!visited[up] && !st.count(up)){
                    visited[up] = true;
                    q.push({up,moves+1});
                }
                if(!visited[down] && !st.count(down)){
                    visited[down] = true;
                    q.push({down,moves+1});
                }
            }
        }
    return -1;}
};