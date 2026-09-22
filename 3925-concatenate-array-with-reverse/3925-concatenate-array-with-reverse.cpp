class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> temp;
        temp = nums;
        reverse(nums.begin(),nums.end());
        for(int i:nums){
            temp.push_back(i);
        }
        return temp;
    }
};