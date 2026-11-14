class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        
        int n = nums.size();
        int sum = INT_MAX;
        for(int i = 0;i<n;i++){
            int minisum = 0;
            for(int j = i;j<n;j++){
                minisum += nums[j];
                int size = j-i+1;
                if(size >= l && size <= r){
                    if(sum > minisum && minisum > 0){
                        sum = min(sum,minisum);
                    }
                }
            }
        }

        if(sum == INT_MAX)  return -1;
        return sum;
    }
};