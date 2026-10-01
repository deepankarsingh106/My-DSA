class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()){
            return false;
        }
        
        map<char,bool> mp;
        
        int arr[26] = {0};
        
        for(char ch:s){
            arr[ch-'a']++;
            mp[ch] = true;
        }
    
        int brr[26] = {0};
        
        for(char ch:t){
            brr[ch-'a']++;
            if(mp.find(ch) == mp.end()){
                return false;
            }
        }

        for(int i=0;i<26;i++){
            if(arr[i] != brr[i]){
                return false;
            }
        }

    return true;}
};