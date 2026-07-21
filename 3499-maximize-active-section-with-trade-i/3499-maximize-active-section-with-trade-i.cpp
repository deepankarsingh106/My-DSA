class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cnt1 = count(s.begin(),s.end(),'1');

        vector<int> zeroblock;
        int i = 0;
        while(i<n){
            int start = i;

            while(i < n && s[i] == s[start])    ++i;
            
            if(s[start] == '0'){
                zeroblock.push_back(i-start);
            }

        }

        int m = zeroblock.size();

        if(m < 2){
            return cnt1;
        }

        int bestgain = 0;

        for(int i = 0;i+1<m;i++){
            bestgain = max(bestgain,zeroblock[i]+zeroblock[i+1]);
        }

        return cnt1 + bestgain;

    }
};