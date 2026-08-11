class Solution {
private:
    bool check(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    int maxVowels(string s, int k) {

       int n = s.size();

       int c = 0;

        for(int i = 0;i<k;i++){
            if(check(s[i])) c++;
        } 
        int maxi = c;
        int l = 0;
        for(int i = k;i<n;i++){
            if(check(s[i])) c++;
            if(check(s[l++])) c--;
            maxi = max(maxi,c);
        }
        return maxi;
    }
};