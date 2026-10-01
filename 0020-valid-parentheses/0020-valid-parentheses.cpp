class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n == 1)  return false;
        stack<char> check;
        for(int i = 0;i<n;i++){
            if(s[i] == '[' || s[i] == '{' || s[i] == '('){
                check.push(s[i]);
            }
            else{
                if(check.empty()){
                    return false;
                }
                else if(s[i] == ')'){
                    if(check.top() != '('){
                        return false;
                    }
                    else check.pop();
                }
                else if(s[i] == ']'){
                    if(check.top() != '['){
                        return false;
                    }
                    else check.pop();
                }
                else if(s[i] == '}'){
                    if(check.top() != '{'){
                        return false;
                    }
                    else check.pop();
                }
            }
        }
    return check.empty();}
};