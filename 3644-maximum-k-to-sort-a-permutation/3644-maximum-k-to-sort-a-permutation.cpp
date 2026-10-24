class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        
        int n = nums.size();

        int k = -1;
        for(int i = 0;i<n;i++){
            if(i != nums[i]){
                k&= nums[i];
                if(k == 0)  return 0;
            }
        }

        return max(k,0);
    }
};