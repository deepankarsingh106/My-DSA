class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int d = 0;
        for(int i:nums){
            while(i){
                int l = i%10;
                if(l == digit)  d++;
                i/=10;  
            }
        }
        return d;
        
    }
};