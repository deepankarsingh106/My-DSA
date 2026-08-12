class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        unordered_map<int,int> mp;
        
        int maxi = 0;
        int start = 0;
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
            while(mp[nums[i]] > k){
                mp[nums[start]]--;
                start++;
            }
            maxi = max(maxi,i-start+1);
        }
    return maxi;}
};