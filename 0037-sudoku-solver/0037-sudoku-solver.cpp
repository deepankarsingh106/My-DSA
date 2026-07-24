class Solution {
private:

bool isSafe(int row,int col,vector<vector<char>>& board,int val){
    for(int i = 0;i<board.size();i++){
        
        //row check
        if(board[row][i] == val+'0'){
            return false;
        }
        //checking for the column
        if(board[i][col] == val+'0'){
            return false;
        }

        // checking for the  matrix

        int matrow = 3*(row/3) + i/3;
        int matcol = 3*(col/3) + i%3;

        if(board[matrow][matcol] == val+'0'){
            return false;
        }
    }

     return true;
}
bool solve(vector<vector<char>>& board){

    int n = board.size();

    for(int row = 0;row<n;row++){
        for(int col = 0;col<n;col++){

            // cell empty
            if(board[row][col] == '.'){

                for(int val = 1;val<=9;val++){

                    if(isSafe(row,col,board,val)){
                        board[row][col] = '0'+val;

                        bool aagesolution = solve(board);

                        if(aagesolution){
                            return true;
                        }
                        else{
                            board[row][col] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);   
    }
};