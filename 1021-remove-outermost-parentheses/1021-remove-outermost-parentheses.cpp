class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();

        string ans = "";
        stack<char>st;

        for(char ch:s){
            if(ch == '('){

                if(!st.empty()){
                    ans.push_back(ch);
                }
                st.push('(');
            }
            else{
                st.pop();
                if(!st.empty()){
                    ans.push_back(ch);
                }
            }
        }
    return ans;}
};