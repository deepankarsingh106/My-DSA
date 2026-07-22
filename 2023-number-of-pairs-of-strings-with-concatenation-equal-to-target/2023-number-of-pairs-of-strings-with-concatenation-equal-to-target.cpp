class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int c = 0;
        // frequency
        map<string,int> mp;
        
        for(string s: nums){
            mp[s]++;
        }

        for(string s: nums){
            // s is a prefix of the target
            if(target.find(s) == 0){
                string need = target.substr(s.size());
                
                if(mp.find(need) != mp.end()){
                    c += mp[need];   
                }
                

                if(need == s)   c--;      
            } 

            
        }
        return c;
    }
};