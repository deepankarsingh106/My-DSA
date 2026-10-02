class Solution {
    vector<string>ans;
    void backtrack(string s,int o,int c,int n){
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }

        if(o < n){
            s.push_back('(');
            backtrack(s,o+1,c,n);
            s.pop_back();
        }
        if(c < o){
            s.push_back(')');
            backtrack(s,o,c+1,n);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        
        string s;
        s.reserve(2*n);
        backtrack(s,0,0,n);
        return ans;
    }
};