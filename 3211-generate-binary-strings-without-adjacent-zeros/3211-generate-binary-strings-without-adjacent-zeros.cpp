class Solution {
private:
    void solve(string &s,int &n,vector<string>&ans){
        if(s.size() == n){
            ans.push_back(s);
            return;
        }
        int m = s.size();
        if(s[m-1] == '0'){
            s += '1';
            solve(s,n,ans);
            s.pop_back();
        }
        else{
            s += '0';
            solve(s,n,ans);
            s.pop_back();
            s += '1';
            solve(s,n,ans);
            s.pop_back();
        }
    }
public:
    vector<string> validStrings(int n) {
        vector<string>ans;
        string s = "0";
        solve(s,n,ans);
        string s2 = "1";
        solve(s2,n,ans);
        return ans;
    }
};