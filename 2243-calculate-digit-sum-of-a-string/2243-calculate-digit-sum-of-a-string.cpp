class Solution {
public:
    string digitSum(string s, int k) {
       
        string d="";bool flag = false;
        while(s.size() > k){
            string temp = ""; int n = s.size();
            int sum = 0;
            for(int i = 0;i<n;){
                int sum = 0;
                for(int j = i;j<min(i+k,n);j++){
                    sum += (s[j]-'0');
                }
                i += k;
                temp += (to_string(sum));sum=0;
            }
            s = temp;
        }
        return s;

    }
};