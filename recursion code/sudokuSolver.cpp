#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool isValid(vector<vector<char>>& board,int row,int col,char c)
{
    for(int i=0;i<9;i++)
    {
        //col checking
        if(board[row][i]==c)return false;

        //row checking
        if(board[i][col]==c)return false;

        //checking 3*3 sub Matrix
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)return false;
    }
    return true;
}
bool solve(vector<vector<char>>& board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board.size();j++)
        {
            if(board[i][j]=='.')
            {
                for(char c='1';c<='9';c++)
                {
                    if(isValid(board,i,j,c))
                    {
                        board[i][j]=c;
                        if(solve(board))return true;
                        else board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board)
{
    solve(board);
}
int main()
{
    vector<vector<char>>board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

    solveSudoku(board);
    for(auto x:board)
    {
        for(auto y:x)cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}
