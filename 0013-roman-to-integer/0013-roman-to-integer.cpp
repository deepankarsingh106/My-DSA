class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        
        unordered_map<char,int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        long long c = 0;
        
        for(int i = 0;i<n;i++){
            if(i+1 < n && mp[s[i]] < mp[s[i+1]]){
                c -= mp[s[i]];
            }
            else{
                c += mp[s[i]];
            }
        }
    return c;}
};