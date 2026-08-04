class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i = 0;i<n;i++){
            if(mini > nums[i]){
                mini = nums[i];
            }
            if(maxi < nums[i]){
                maxi = nums[i];
            }
        }
        int arr[101] = {0};
        for(int i = 0;i<n;i++){
            arr[nums[i]]++;
        }
        for(int i = mini;i<=maxi;i++){
            if(arr[i] == 0){
                ans.push_back(i);
            }
        }
    return ans;}
};