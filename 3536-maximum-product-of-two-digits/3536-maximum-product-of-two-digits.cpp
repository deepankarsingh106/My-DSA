class Solution {
public:
    int maxProduct(int n) {
        string digits=to_string(n);

        sort(digits.begin(), digits.end());

        int max1=digits[digits.size()-1]-'0';
        int max2=digits[digits.size()-2]-'0';

        return max1*max2;
    }
};