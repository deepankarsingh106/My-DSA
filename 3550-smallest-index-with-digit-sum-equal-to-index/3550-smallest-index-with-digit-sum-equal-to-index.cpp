class Solution {
    int sumdigit(int i){
        int s = 0;
        while(i){
            s += (i%10);
            i/=10;
        }

        return s;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(i == sumdigit(nums[i])){
                return i;
            }
        }
    return -1;}
};