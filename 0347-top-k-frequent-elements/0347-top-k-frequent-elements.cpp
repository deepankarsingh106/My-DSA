class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int ,int>count;
        
        for(int i = 0;i<n;i++){
            count[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto i:count){
            pq.push(make_pair(i.second,i.first));
        }
        vector<int> ans;
        while(k--){
            auto i = pq.top();
            pq.pop();
            ans.push_back(i.second);
        }
        return ans;
    }
};