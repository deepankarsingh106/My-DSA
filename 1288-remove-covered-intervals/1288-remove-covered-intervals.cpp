class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int c = 0;
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            if(a[0] == b[0]){
                return b[1] < a[1];
            }
            return a[0] < b[0];
        });
        int maxend = intervals[0][1];
        for(int i = 1;i<n;i++){
            if(intervals[i][1] > maxend){
                maxend = intervals[i][1];
            }
            else c++;
        }
    return n-c;}
};