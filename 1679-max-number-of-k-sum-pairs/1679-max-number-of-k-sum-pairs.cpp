class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int c = 0;
        sort(nums.begin(),nums.end());
        int i = 0,j = n-1;

        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum == k){
                c++;
                i++;j--;
            }
            else if(sum > k){
                j--;
            }
            else i++;
        }
        return c;
    }
};