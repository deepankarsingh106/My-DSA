class Solution {
    bool isValid(int r,int c,vector<vector<char>>& board,char ch){

        for(int i = 0;i<9;i++){
            if(i != c && board[r][i] == ch)   return false;
            if(i != r && board[i][c] == ch) return false;
            int matrow = 3*(r/3) + i/3;
            int matcol = 3*(c/3) + i%3;
            if(matrow != r && matcol != c && board[matrow][matcol] == ch){
                return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                
                if(board[i][j] == '.')  continue;
                char ch = board[i][j];
                if(!isValid(i,j,board,ch)){
                    return false;
                }
            }
        }
        return true;
    }
};