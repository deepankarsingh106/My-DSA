class Solution {
private:
    int prod(int i){
        int prod=1;
        while(i>0){
            prod *= (i%10);
            i/=10;
        }
        return prod;
    }
public:
    int smallestNumber(int n, int t) {
        
        for(int i=n;i<101;i++){
            if((prod(i)%t) == 0){
                return i;
            }
        }
    return 0;}
};