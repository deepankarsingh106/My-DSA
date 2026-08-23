class Solution {
public:
    bool sumGame(string num) {
        
        int arr[2] = {0,0};
        int q[2] = {0,0};
        int n = num.size();

        // for(int i = 0;i<n;i++){
        //     if(num[i] == '?')   continue;
        //     else if(i < n/2) arr[0] += num[i];
        //     else arr[1] += num[i];
        // }
        // bool bob = true;
        // for(int i = 0;i<n;i++){
        //     if(num[i] == '?'){
        //         if(bob){
        //             if(i < n/2){
        //                 arr[0] += abs(arr[0]-arr[1]);
        //             }
        //             else{
        //                 arr[1] += abs(arr[0] - arr[1]);
        //             }
        //             bob = false;
        //         }
        //         else{
        //             int sum = abs(arr[0]-arr[1]);
        //             if(i < n/2){
        //                 if(sum != 9){
        //                     arr[0] += sum+1;
        //                 }
        //             }
        //             else{
        //                 if(sum != 9){
        //                     arr[1] += sum+1;
        //                 }
        //             }
        //             bob = true;
        //         }
        //     }   
        // }

        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < n / 2) q[0]++;
                else q[1]++;
            }
            else {
                if (i < n / 2) arr[0] += num[i] - '0';
                else arr[1] += num[i] - '0';
            }
        }

        return 2 * (arr[0] - arr[1]) != 9 * (q[1] - q[0]);
        //return arr[0] != arr[1];
    }
};