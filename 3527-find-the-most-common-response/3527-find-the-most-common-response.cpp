class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int n = responses.size();

        map<string,int> mp;
        int maxi = 0;
        for(int i = 0;i<n;i++){
            map<string,int> tempcheck;
            for(string s: responses[i]){
                if(tempcheck.find(s) == tempcheck.end()){
                    mp[s]++;maxi = max(maxi,mp[s]);
                }
                tempcheck[s]++;
            }
        }

        for(auto i: mp){
            if(i.second == maxi){
                return i.first;
            }
        }    
    return "";}
};