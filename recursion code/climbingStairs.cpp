#include<iostream>
#include<vector>
using namespace std;
int climbStairsHelper(int n,vector<int> &dp)
{
    //base case
    if(n==0)return 1;
    if(n<0)return 0;
    //memoization case
    if(dp[n] != -1)return dp[n];
    //recursive case
    return dp[n]=climbStairsHelper(n-1,dp)+climbStairsHelper(n-2,dp);

}
int climbStairs(int n)
{
    vector<int>dp(n+1,-1);
    return climbStairsHelper(n,dp);

}
int main()
{
    int n=4;//3,2

    int totalWay=climbStairs(n);

    cout<<totalWay<<endl;

    return 0;
}
