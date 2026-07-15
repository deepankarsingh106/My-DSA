class Solution {
public:
int gcd(int a,int b){
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }
    while(a!=b){
        if(a>b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}
    int gcdOfOddEvenSums(int n) {
        int se = n*(n+1),so = pow(n,2);
        return gcd(se,so);
    }
};