class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int maxi = 0;
        int curr=0;
        for(char ch: s){
            if(ch == '(')   curr++;
            else if(ch == ')')    curr--;
            maxi = max(maxi,curr);   
        }
    return maxi;}
};