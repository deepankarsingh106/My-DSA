class Solution {
public:
    void rever(int i ,int j,string &s){
        while(i < j){
            swap(s[i++],s[j--]);
        }
    }
    string smallestNumber(string pattern) {
        int n = pattern.size();
        
        string s(n+1,'1');
        for(int i = 0;i+1<n+1;i++){
            s[i+1] = ((s[i]-'0')+1+'0');
        }
        int i = 0,j=0;
        while(j < s.size () && i < n){
    
            while(j < s.size() && i < n && pattern[i] == 'I'){
                j++;
                i++;
            }
            int start = i;
            while(i < n && pattern[i] == 'D'){
                i++;
            }    
            rever(start,i,s);
    
        }
    return s;}
};