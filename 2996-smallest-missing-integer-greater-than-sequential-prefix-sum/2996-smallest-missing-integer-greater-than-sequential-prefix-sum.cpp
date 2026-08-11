class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = 0,end = 0;
        for(int i = 1;i<n;i++){
            if(nums[i] == nums[i-1] + 1){
                end = i;
            }
            else{
                break;
            }
        }
        sum = accumulate(nums.begin(),nums.begin()+end+1,0);
        auto idx = find(nums.begin(),nums.end(),sum);
        if(idx == nums.end())  return sum;
        else{
            while(idx != nums.end()){
                sum = sum + 1;
                idx = find(nums.begin(),nums.end(),sum);
            }
            return sum;
        }
        return -1;
    }
};