class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int small = nums[0];
        int big = nums[n-1];int c;
        for(int i = 1;i<=small;i++){
            if(big%i == 0 && small%i == 0)  c = i;
        }
    return c;
    }
};