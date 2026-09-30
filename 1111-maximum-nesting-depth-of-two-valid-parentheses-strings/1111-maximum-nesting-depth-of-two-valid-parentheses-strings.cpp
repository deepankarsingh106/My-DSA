class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        
        int n = seq.size();


        int d = 0;
        for(char ch:seq){
            if(ch == '('){
                d++;
                ans.push_back(d%2);
            }
            else{
                ans.push_back(d%2);
                d--;
            }
        }
    return ans;}
};