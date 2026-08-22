class Solution {
public:
    bool checkDivisibility(int n) {
        int s = 0,p = 1,x = n;
        while(x != 0){
            int r = x % 10;
            s += r;
            p*=r;
            x/=10;
        }
    
    if(n%(s+p) == 0){
        return true;
    }
    return false;
    }
};