class Solution {
private:
    // bool isSafe(int row,int col,vector<string> &board,int n){
    //         int x = row,y = col;

    //         //checking the particular row
    //         // left row
    //         while(y >= 0){
    //             if(board[x][y] == 'Q'){
    //                 return true;
    //             }
    //             y--;
    //         }
    //         // rightrow
    //         x = row,y = col;
    //         while(y < n){
    //             if(board[x][y] == 'Q'){
    //                 return true;
    //             }
    //             y++;
    //         }
    //         //upper col
    //         x = row,y = col;

    //         while(x >= 0){
    //             if(board[x][y] == 'Q'){
    //                 return true;
    //             }
    //             x--;
    //         }
    //         //downward col
    //         x = row,y = col;

    //         while(x < n){
    //             if(board[x][y] == 'Q'){
    //                 return true;
    //             }
    //             x++;
    //         }

    //         // checking the diagonal left upward
    //         x = row,y = col;
            
    //         while(x >= 0 && y >= 0){
    //             if(board[x][y] == 'Q'){
    //                 return true;
    //             }
    //             x--;y--;
    //         }
            
    //         //check for the diagonal right downward
    //         x = row;y = col;

    //         while(x < n && y < n){
    //             if(board[x][y] == 'Q'){
    //                 return true;
    //             }
    //             x++;y++;
    //         }
            
    //         // checking the diagonal left downward
    //         x = row;y = col;

    //         while(x < n && y >= 0){
    //             if(board[x][y] == 'Q'){
    //                 return true;
    //             }
    //             x++;y--;
    //         }
            
    //         //check for the diagonal right upward
    //         x = row;y = col;
    //          while(x >= 0 && y < n){
    //             if(board[x][y] == 'Q'){
    //                 return true;
    //             }
    //             x--;y++;
    //         }

    //         return false;
    //     }
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        //same as N Queen
        //vector<string> board(n,string(n,'.'));
        unordered_map<int,int>row_count,col_count,diag_count,anti_diag;

        unordered_set<long long> active_lamp;
        
        for(int i = 0;i<lamps.size();i++){
            int x = lamps[i][0];
            int y = lamps[i][1];
            if(active_lamp.find(1ll*x*n+y) == active_lamp.end()){
                active_lamp.insert(1ll*x*n+y);
                row_count[x]++;
                col_count[y]++;
                diag_count[x-y]++;
                anti_diag[x+y]++;
            }
        }

        vector<int>ans;

        for(int i = 0;i<queries.size();i++){
            int row = queries[i][0];
            int col = queries[i][1];
            if(row_count[row] > 0 || col_count[col] > 0 ||  diag_count[row-col] > 0 ||  anti_diag[row+col] > 0){
                ans.push_back(1);
            }else   ans.push_back(0);

                for(int i = row-1;i<=row+1;i++){
                    for(int j = col-1;j<=col+1;j++){
                        if(i < 0 || j < 0 || i >= n || j >= n)  continue;
                        if(active_lamp.erase(1ll*i*n+j)){
                                row_count[i]--;
                                col_count[j]--;
                                anti_diag[i+j]--;
                                diag_count[i-j]--;
                        }
                    }
                }
            }
        return ans;
    }
};