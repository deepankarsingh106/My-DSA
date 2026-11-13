class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int n = bills.size();

        int five = 0,ten = 0;
        
        for(int i = 0;i<n;i++){
            if(bills[i] == 5)   five++;
            else if(bills[i] == 10){
                if(five-1 < 0)  return false;
                five -= 1;ten++;
            } 
            else{
                if((five - 3 < 0) && (five-1 < 0 || ten-1 < 0)) return false;
                else if(five > 0 && ten > 0){
                    five -= 1;ten -= 1;
                }  
                else five -= 3;
            }
        }
    return true;}
};