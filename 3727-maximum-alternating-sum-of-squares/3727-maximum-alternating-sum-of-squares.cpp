class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1){
            return nums[0]*nums[0];
        }
        int c = n/2;
        if(n&1){
            c++;
        }
        long long ans = 0;

        sort(nums.begin(),nums.end());
        
        int i = 0,j=n-1; 
        while(i < j && c > 0){
            if(abs(nums[i]) >= abs(nums[j])){
                ans += pow(abs(nums[i++]),2);
            }else{
                ans += pow(abs(nums[j--]),2);
            }
            c--;
        }

        while(i <= j){
            ans -= pow(abs(nums[i++]),2);
        }

        return ans;
    }
};