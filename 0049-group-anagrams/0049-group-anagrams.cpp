class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();
        vector<vector<string>> ans;

        if(strs.size() == 0){
            return {{""}};
        }

        unordered_map<string,vector<string>> mp;


        for(int i = 0;i<n;i++){

            string temp = strs[i];

            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);
        }

        for(auto i:mp){
            vector<string> temp = i.second;

            ans.push_back(temp);
        }

    return ans;}
};