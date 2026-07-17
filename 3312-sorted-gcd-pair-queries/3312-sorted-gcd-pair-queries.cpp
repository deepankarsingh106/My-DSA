class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        
        int m = *max_element(nums.begin(),nums.end());
        
        vector<long long>freq(m+1,0);
        
        // storing the frequency of each element 
        for(int num:nums){
            freq[num]++;
        }

        // 
        for(int i = 1;i<=m;i++){
            for(int j=i*2;j<=m;j+=i){
                freq[i] += freq[j];
            }
        }

        for (int i = 1; i <= m; i++) {
            freq[i] = freq[i] * (freq[i] - 1) / 2;
        }

        for(int i =m;i>=1;i--){
            for(int j=i*2;j<=m;j+=i){
                freq[i] -= freq[j];
            }
        }

        for(int i = 1;i<=m;i++){
            freq[i] += freq[i-1];
        }

        vector<int> ans;
        for(long long q:queries){
            q++;
            int pos = lower_bound(freq.begin(),freq.end(),q) - freq.begin();
            ans.push_back(pos);
        }
        return ans;
    }
};