#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool isSafe(int row,int col,vector<string> &board,int n)
{
    int dumRow=row;
    int dumCol=col;
    while(row>=0 && col>=0)
    {
        if(board[row--][col--]=='Q')return false;
    }
    row=dumRow;
    col=dumCol;
    while(col>=0)
    {
        if(board[row][col--]=='Q')return false;
    }
    col=dumCol;
    while(row<n && col>=0)
    {
        if(board[row++][col--]=='Q')return false;
    }
    return true;
}
void helper(int col,int n,vector<string> &board,vector<vector<string>> &ans)
{
    //base case
    if(col==n)
    {
        ans.push_back(board);
        return ;
    }
    //recursive case
    for(int row=0;row<n;row++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col]='Q';
            helper(col+1,n,board,ans);
            board[row][col]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0;i<n;i++)
    board[i]=s;
    helper(0,n,board,ans);
    return ans;
}
int main()
{
    int n=4;

    vector<vector<string>>ans=solveNQueens(n);
    for(auto x:ans)
    {
        for(auto y:x)cout<<y<<"  ";
        cout<<endl;
    }

    return 0;
}
