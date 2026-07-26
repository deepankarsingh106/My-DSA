class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        //reverse(nums.begin(),nums.end());
        long long int p = nums[n-1]*1ll*nums[n-2]*nums[n-3];
        long long int q = nums[0]*1ll*nums[1]*nums[n-1];
        return max(p,q);  
    }
};