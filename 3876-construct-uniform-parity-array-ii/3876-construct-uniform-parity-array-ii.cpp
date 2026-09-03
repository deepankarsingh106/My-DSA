class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
        int n = nums1.size();

        int xmin = nums1[0];
        bool odd = 0;
        for(int i = 0;i<n;i++){
        
            xmin = min(xmin,nums1[i]);
        
            odd |= (nums1[i]&1);
        } 

        return (xmin&1) == odd;
    }
};