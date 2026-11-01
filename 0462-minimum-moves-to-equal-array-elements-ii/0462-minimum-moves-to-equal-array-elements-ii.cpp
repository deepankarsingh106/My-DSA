class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int e = 0;
        if(n&1){
            e = nums[n/2];
        }else{
            e = (nums[n/2] + nums[(n/2) - 1])/2;
        }

        int c = 0;
        for(int i:nums){
            c += abs(i-e);
        }

        return c;
    }
};