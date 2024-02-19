#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void countSquaresHelper(vector<vector<char>>& matrix,vector<vector<int>>& dp,int i,int rows,int cols)
{
    //base case
    if(i>=rows)return ;
    //recursive case
    for(int j=1;j<cols;j++)
    {
        if(matrix[i][j]=='0')dp[i][j]=0;
        else dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+matrix[i][j]-'0';
    }
    countSquaresHelper(matrix,dp,i+1,rows,cols);
}
int maximalSquare(vector<vector<char>>& matrix)
{
    int rows=matrix.size();
    int cols=matrix[0].size();

    vector<vector<int>>dp(rows,vector<int>(cols,0));

    for(int i=0;i<cols;i++)dp[0][i]=matrix[0][i]-'0';
    for(int j=0;j<rows;j++)dp[j][0]=matrix[j][0]-'0';

    countSquaresHelper(matrix,dp,1,rows,cols);

    int maxSquare=0;
    for(auto x:dp)
    {
        for(auto y:x)maxSquare=max(maxSquare,y);
    }
    return maxSquare*maxSquare;
}
int maximumalSquareIterative(vector<vector<char>>& matrix)
{
    int rows=matrix.size();
    int cols=matrix[0].size();

    vector<vector<int>>dp(rows,vector<int>(cols,0));

    for(int i=0;i<cols;i++)dp[0][i]=matrix[0][i]-'0';
    for(int j=0;j<rows;j++)dp[j][0]=matrix[j][0]-'0';
    for(int i=1;i<rows;i++)
    {
        for(int j=1;j<cols;j++)
        {
             if(matrix[i][j]=='0')dp[i][j]=0;
        else dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+matrix[i][j]-'0';
        }
    }

    int maxSquare=0;
    for(auto x:dp)
    {
        for(auto y:x)maxSquare=max(maxSquare,y);
    }
    return maxSquare*maxSquare;
}
int main()
{
    vector<vector<char>>matrix={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};

    int ans=maximalSquare(matrix);
    cout<<ans<<endl;

    int ans1=maximumalSquareIterative(matrix);
    cout<<ans1<<endl;
    return 0;
}
