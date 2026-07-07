class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0,x=0;
        string s = to_string(n);
        for(int i = 0;i<s.size();i++){
            if(s[i] == '0') continue;
            sum += (s[i]-'0');
            x = (x*10) + (s[i]-'0');
        }
        return x*sum;
    }
};