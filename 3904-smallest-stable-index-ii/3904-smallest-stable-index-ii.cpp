class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> arr(n);

        arr[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--){
            arr[i] = min(arr[i+1], nums[i]);
        }

        int mini = INT_MAX,val = -1;
        for(int i = 0;i<n;i++){
            val = max(val,nums[i]);
            int diff = val-arr[i];
            if(diff <= k){
                return i;
            }
        }

        if(mini == INT_MAX){
            return -1;
        }
        return mini;
    }
};