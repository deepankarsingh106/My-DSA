class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();

        stack<char>st;
        int c=0;
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                st.push('(');
            }
            else{
                if(st.size() == 0){
                    c++;
                }
                else    st.pop();
            }
        }
    return c + st.size();}
};