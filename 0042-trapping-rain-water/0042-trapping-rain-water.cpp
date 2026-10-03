class Solution {
public:
    int trap(vector<int>& h) {
        
        int n = h.size();

        int left = 0,right = n-1,w=0;

        int leftmax = 0,rightmax =0;

        while(left < right){

            if(h[left] <= h[right]){
                
                leftmax = max(leftmax,h[left]);
                w += leftmax-h[left];
                left++;
            }   
            else{
                
                rightmax = max(rightmax,h[right]);
                w += rightmax-h[right];
                right--;
            }   
        }

        return w;
    }
};