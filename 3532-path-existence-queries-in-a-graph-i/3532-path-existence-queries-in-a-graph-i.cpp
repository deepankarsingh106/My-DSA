class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        int m = queries.size();
        vector<int>comp(n,0);int c = 0;
        for(int i = 1;i<n;i++){
            if(nums[i]-nums[i-1] > maxDiff){
                c++;
            }
            comp[i] = c;
        }
        for(auto i: queries){
            ans.push_back(comp[i[0]] == comp[i[1]]);
        }
    return ans;}
};