class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(char ch:s){
            mp[ch]++;
        }
        priority_queue<pair<int,char>> pq;
        string ans = "";
        for(auto i:mp){
            pq.push(make_pair(i.second,i.first));
        }
        while(!pq.empty()){
            pair<int,char> e = pq.top();pq.pop();
            while(e.first > 0){
                ans += e.second;
                e.first--;
            }
        }
        return ans;
    }
};