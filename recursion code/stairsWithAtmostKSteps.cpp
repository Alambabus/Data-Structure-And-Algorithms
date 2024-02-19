#include<iostream>
#include<vector>
using namespace std;
int climbStairsHelper(int n,vector<int> &dp,int k)
{
    //base case
    if(n==0)return 1;
    if(n<0)return 0;

    //memoization case
    if(dp[n] != -1)return dp[n];

    int ans=0;
    for(int i=1;i<=k;i++)
    ans+=climbStairsHelper(n-i,dp,k);

    return dp[n]=ans;
}
int climbStairs(int n,int k)
{
    vector<int>dp(n+1,-1);
    return climbStairsHelper(n,dp,k);

}
int main()
{
    int n=3;//3,2
    int k=3;
    int totalWay=climbStairs(n,k);

    cout<<totalWay<<endl;

    return 0;
}
