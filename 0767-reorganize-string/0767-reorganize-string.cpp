class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char,int> freq;
        
        for(char ch:s){
            freq[ch]++;
        }

        priority_queue<pair<int,char>> pq;

        for(auto &i:freq){
            pq.push({i.second,i.first});
        }

        string ans = "";
        while(pq.size() >= 2){

            pair<int,char> a = pq.top();pq.pop();
            int cnt1 = a.first;

            ans += a.second;
            pair<int,char> b = pq.top();pq.pop();
            int cnt2 = b.first;

            ans += b.second;
            if(--cnt1 > 0){
                pq.push({cnt1,a.second});
            }

            if(--cnt2 > 0){
                pq.push({cnt2,b.second});
            }
        }

        if(!pq.empty()){
            pair<int,char> left = pq.top();pq.pop();
            if(left.first > 1){
                return "";
            }
            ans += left.second;
        }

        return ans;
    }
};