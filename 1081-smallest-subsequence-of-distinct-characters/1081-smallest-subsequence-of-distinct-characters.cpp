class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        
        string ans = "";
        // monotonic stack
        stack<char> st;
        
        // for checking the visited or not
        vector<bool>visited(26,false);
        
        // last idx seen 
        vector<int> lastidx(26,-1);
       
        for(int i =0;i<n;i++){
            lastidx[s[i]-'a'] = i;
        }

        for(int i = 0;i<n;i++){
            if(visited[s[i]-'a'])  continue;
            char current = s[i];
            while(!st.empty() && st.top() > current && lastidx[st.top() - 'a'] > i){
                    visited[st.top()-'a'] = false;
                    st.pop();
            }
            st.push(current);
            visited[s[i]-'a'] = true;
        }
        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};