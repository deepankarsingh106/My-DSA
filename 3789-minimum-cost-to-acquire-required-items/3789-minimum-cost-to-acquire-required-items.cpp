class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        if(need1 == 0 && need2 == 0)    return 0;

        long long calcost1 = 1ll*cost1*need1 + 1ll*need2*cost2;
        long long calcost2 = 0,calcost3 = 0;
        int sub = min(need1,need2);
        int sub1 = max(need1,need2);

        calcost2 = sub*1ll*costBoth;
        calcost2 += ((1ll*(need1-sub))*cost1);    
        calcost2 += ((1ll*(need2-sub))*cost2);
        long long ans = min(calcost2,calcost1);

        calcost3 = sub1 * 1ll * costBoth;
        

        ans = min(ans,calcost3);
        return ans;

    }
};