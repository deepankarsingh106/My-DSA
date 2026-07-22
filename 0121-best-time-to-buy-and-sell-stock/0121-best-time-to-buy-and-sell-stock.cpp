class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprofit = 0;
        int minprice = INT_MAX;
        for(int i = 0;i<n;i++){
            if(minprice > prices[i])    minprice = prices[i];
            else{
                maxprofit = max(maxprofit,prices[i]-minprice);
            }
        }
        return maxprofit;
    }
};