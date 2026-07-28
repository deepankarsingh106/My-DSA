class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        map<char,int> mp;

        for(char ch:s){
            mp[ch]++;
        }

        int j = 0;
        for(auto &i:mp){ // it should be passed by refrence to inherent the change
            int count = i.second;
            while(count-2 >= 0){
                s[j] = i.first;
                s[n-1-j] = i.first;
                j++;
                count -= 2;
            }
            i.second = count;
        }

        for(auto &i:mp){
            int count = i.second;
            if(count > 0){
                s[j] = i.first;
                j++;
            }
        }
        return s;        
    }
};