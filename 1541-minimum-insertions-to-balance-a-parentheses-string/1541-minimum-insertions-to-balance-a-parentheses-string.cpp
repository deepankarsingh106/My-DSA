class Solution {
public:
    int minInsertions(string s) {
        
        int n = s.size();
        
        int c = 0,ans = 0,x = 0; 
    
        for(int i = 0;i<n;i++){

            if(s[i] == '('){
                ++x;
            }else{
                if(i < n-1 && s[i+1] == ')'){
                    ++i;
                }else{
                    ++ans;
                }
                if(x == 0){
                    ++ans;
                }else{
                    --x;
                }
                
            }
            
        }
        ans += (2*x);
        return ans;
    }
};