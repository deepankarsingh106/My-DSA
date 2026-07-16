class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixGCD(n,0);
        
        int maxi = INT_MIN;
        
        for(int i=0;i<n;i++){
            maxi= max(maxi,nums[i]);
            prefixGCD[i] = gcd(maxi,nums[i]);
        }

        sort(prefixGCD.begin(),prefixGCD.end());
        int i =0,j=prefixGCD.size()-1;
        long long  sum = 0;
        while(i<j){
            sum += gcd(prefixGCD[i++],prefixGCD[j--]);
        }
        return sum;
    }
};