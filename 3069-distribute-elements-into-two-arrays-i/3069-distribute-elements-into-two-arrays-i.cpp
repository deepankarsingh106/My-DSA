class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> a1,a2;
        
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        
        for(int i = 2;i<n;i++){
            int n1 = a1.size();
            int n2 = a2.size();
            if(a1[n1-1] > a2[n2-1]){
                a1.push_back(nums[i]);
            }
            else{
                a2.push_back(nums[i]);
            }
        }
        for(int i = 0;i<a2.size();i++)  a1.push_back(a2[i]);
        return a1;
    }
};