#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SolveSudoku {
public:
    //dealing with reference no boolean return
    void solveSudoku(vector<vector<char> > &board) {
         solver(board);
    }
    //dfs recursively solver
    bool solver(vector<vector<char> > &board)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == 'x')
                {
                    for(int k = 1; k <= 9; k++)
                    {
                        board[i][j] = k + '0';
                        if(ValidSudoku(board, i, j) && solver(board))
                            return true;
                    }
                    board[i][j]='x';
                    return false;
                }
            }
        } 
        return true;
    }    

    bool ValidSudoku(vector<vector<char> > &board, int row, int col)
    {
         //validate row
         char num = board[row][col];
         for(int i = 0; i < 9; i++)
         {
            if(i==row) continue;
            if(num==board[i][col])
                return false;
         }
        
         //validate column
         for(int j=0;j<9;j++)
         {
            if(j==col) continue;
            if(num==board[row][j])
                return false;
         }
   
         //check 3 by 3 cubic
         int irow =row / 3 * 3;
         int icol =col / 3 * 3;
         for(int i = 0; i < 3 ;i++)
         { 
            for(int j = 0;j<3;j++)
            {
                if(irow+i == row && icol + j == col) 
                    continue;
                else if(num == board[irow + i][icol + j])
                    return false;
            }
         } 
         return true;
    }
};

int main()
{
    //testing    
    
    return 0;
}
