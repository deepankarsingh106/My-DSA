class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> parent;
    void dfs(string word,string &beginWord,vector<string> &path){

        if(word == beginWord){
            vector<string> temp = path;
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            return;
        }

        for(string &i:parent[word]){
            path.push_back(i);
            dfs(i,beginWord,path);
            path.pop_back();
        }        
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(),wordList.end());

        if (!st.count(endWord)) return {};
        
        unordered_map<string,int> lvl;

        queue<string>q;
        
        lvl[beginWord] = 0;

        q.push(beginWord);

        while(!q.empty()){
            string word = q.front();
            int currlvl = lvl[word];
            q.pop();

            int i = 0;string temp = word;
            while(i < word.size()){
                
                char original = temp[i];

                for(char ch = 'a';ch <= 'z';ch++){

                    if(ch == original)  continue;

                    temp[i] = ch;

                    if(!st.count(temp)) continue;

                    if(!lvl.count(temp)){
                        lvl[temp] = currlvl + 1;
                        q.push(temp);
                        parent[temp].push_back(word);
                    }
                    else if(lvl[temp] == currlvl + 1){
                        parent[temp].push_back(word);
                    }
                }
                temp = word;i++;
            } 
        }

        if(!lvl.count(endWord)){
            return {};
        }

        vector<string> path;

        path.push_back(endWord);

        dfs(endWord,beginWord,path);

        return ans;
    }
};