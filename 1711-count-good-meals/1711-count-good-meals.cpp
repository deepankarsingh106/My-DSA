class Solution {
public:
    int mod = 1e9+7;
    int countPairs(vector<int>& deliciousness) {
        int n = deliciousness.size();
        
         map<int,int> mp;
        // for(int i = 0;i<n;i++){
        //     mp[deliciousness[i]]++;
        // } 

        int count = 0;
        for(int i:deliciousness){
            int pow = 1;

            for(int j = 0;j<22;j++){
                if(mp.find(pow - i) != mp.end()){
                    count += mp[pow-i];
                    count %= mod;
                }
                pow *= 2;
            }
            mp[i]++;

            
        }

        return count;
    }
};