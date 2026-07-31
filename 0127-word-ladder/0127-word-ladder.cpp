class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int n = wordList.size();
        
        unordered_set<string> st(wordList.begin(),wordList.end());

        queue<pair<string,int>> q;

        q.push({beginWord,1});

        st.erase(beginWord);

        while(!q.empty()){

            string s = q.front().first;
            
            int steps = q.front().second;
            
            if(s == endWord)    return steps;
            q.pop();
            
            for(int i = 0;i < s.size();i++){
                char original = s[i];
                for(char ch = 'a';ch <= 'z';ch++){
                    s[i] = ch;
                    if(st.find(s) != st.end()){
                        st.erase(s);
                        q.push({s,steps+1});
                    }
                }
                s[i] = original;
            }
        }
        // no sequence match or not found the end word
        return 0;

    }
};