class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int winner = arr[0],streak = 0;

        for(int i = 1;i<n;i++){
            if(winner > arr[i]){
                streak++;
            }
            else {
                winner = arr[i];
                streak = 1;
            }
            if(streak == k){
                return winner;
            }
        }
    return winner;}
};