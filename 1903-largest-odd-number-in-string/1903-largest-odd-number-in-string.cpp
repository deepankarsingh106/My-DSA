class Solution {
public:
    string largestOddNumber(string num) {
        
        int n = num.size();

        string ans = "";
        int j = 0;
        for(int i = 0;i<n;i++){
            if((num[i]-'0')&1){
                string_view part(num.data()+j,i-j+1);
                ans += part;
                j=i+1;
            }
        }
        return ans;

    }
};