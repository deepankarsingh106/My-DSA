class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int c = 0;
        int sum = 0;
        
        vector<int>pref(n);
        pref[0] = nums[0];
        for(int i = 1;i<n;i++){
            pref[i] += pref[i]+pref[i-1];
        }
        map<int,int>mp;
        for(int i = 0;i<n;i++){
            sum += nums[i];

            if(sum == k){
                c++;
            }
            if(mp.find(sum-k) != mp.end()){
                c += mp[sum-k];
            }
            mp[sum]++;
            
        }
        return c;
    }
};