class Solution {
private:
public:
    int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        

        int n = s.size();
        int m = queries.size();
        
        vector<int> compressed,pos;
        
        for(int i = 0;i<n;i++){
            if(s[i] == '0') continue;
            pos.push_back(i);
            compressed.push_back(s[i]-'0');    
        }
        
        vector<long long > prefixSum(compressed.size()+1,0);
        vector<long long > prefixNum(compressed.size()+1,0);
        
        vector<long long >pow10(compressed.size()+1,1);

        for(int i = 1;i<pow10.size();i++){
            pow10[i] = (1ll*pow10[i-1]*10)%MOD;
        }      
     
        for(int i = 0;i<compressed.size();i++){
            prefixSum[i+1] = prefixSum[i] + compressed[i];
            prefixNum[i+1] = ((prefixNum[i]*1ll*10) + compressed[i])%MOD;
        }


        vector<int>ans;
        for(int i = 0;i<queries.size();i++){
                int l = queries[i][0];
                int r = queries[i][1];
                int low = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
                int high = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

                if(low > high){
                    ans.push_back(0);
                    continue;
                }

                long long sum = prefixSum[high+1] - prefixSum[low];
                int len = high-low+1;
                long long x = (prefixNum[high+1]-((prefixNum[low] * pow10[len]) % MOD)+MOD) %MOD;         

                ans.push_back((x*sum*1ll)%MOD);
        }
        return ans;
    }
};