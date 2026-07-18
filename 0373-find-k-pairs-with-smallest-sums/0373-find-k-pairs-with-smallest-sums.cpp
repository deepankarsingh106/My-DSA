class compare{
    public:
    bool operator()(tuple<int, int, int> &a,tuple<int, int, int> &b){
        return get<0>(a) > get<0>(b); 
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        int m = nums2.size();

        if(n == 0 || m == 0)    return {};
        priority_queue<tuple<int, int, int>,vector<tuple<int, int, int>>,compare> pq;
        
        set<pair<int,int>> visited;
        
        vector<vector<int>> ans;
        
        pq.push({nums1[0]+nums2[0],0,0});
        visited.insert({0,0});

        while(k-- && !pq.empty()){

            auto[sum,i,j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i],nums2[j]});

            if(i+1 < n && !visited.count({i+1,j})){
                pq.push({nums1[i+1]+nums2[j],i+1,j});
                visited.insert({i+1,j});
            }
            if(j+1 < m && !visited.count({i,j+1})){
                pq.push({nums1[i]+nums2[j+1],i,j+1});
                visited.insert({i,j+1});
            }

        }
        return ans;

    }
};