class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char ch:word){
            freq[ch-'a']++;
        }
        int count = 0;

        sort(freq.begin(),freq.end(),greater<int>());
        
        for(int i = 0;i<26;i++){
            if(freq[i] == 0)    break;
            if(i < 8){
                count += freq[i];
            }else if(i >= 8 && i < 16){
                count += freq[i]*2;
            }else if(i>=16 && i < 24){
                count += freq[i]*3;
            }else{
                count += freq[i]*4;
            }
        }
    return count;}
};