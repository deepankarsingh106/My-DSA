class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        int n = img1.size();
        vector<pair<int,int>> ones1,ones2;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){

                if(img1[i][j] == 1){
                    ones1.push_back({i,j});
                }
                if(img2[i][j] == 1){
                    ones2.push_back({i,j});
                }
            }
        }


        unordered_map<int,int> freq;

        int maxi = 0;
        for(auto [r1,c1]:ones1){
            for(auto [r2,c2]:ones2){
                int dr = r1-r2;
                int dc = c1-c2;

                int count = dr*100+dc;
                freq[count]++;
                maxi = max(maxi,freq[count]);
            }
        }

        return maxi;
    }
};