class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }
        int p = 1;
        while(mp.find(k*p) != mp.end()){
            p++;
        }
        return k*p;
    }
};