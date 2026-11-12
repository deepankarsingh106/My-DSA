class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int n = nums.size();

        int l1 = 1,l2=1;
        //strictly increasing
        int c = 1;
        for(int i = 0;i+1<n;i++){
            if(nums[i] < nums[i+1]){
                c++;
            }
            else{
                l1=max(l1,c);c=1;
            }
        }
         l1=max(l1,c);
        //strictly decreasing
        c=1;
        for(int i = 0;i+1<n;i++){
            if(nums[i] > nums[i+1]){
                c++;
            }
            else{
                l2=max(l2,c);c=1;
            }
        }
        l2=max(l2,c);
    return max(l1,l2);}
};