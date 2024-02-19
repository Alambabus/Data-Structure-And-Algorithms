#include<iostream>
#include<vector>
using namespace std;
int mod=1000000007;
long long numberOfWaysHelper(long long N,vector<long long> &dp)
{
    //base case
    if(N==0)return 1;
    if(N<0)return 0;
    //memoization case
    if(dp[N] != -1)return dp[N];
    //recursive case
    return dp[N]=(numberOfWaysHelper(N-1,dp)%mod+numberOfWaysHelper(N-2,dp)%mod)%mod;
}
long long numberOfWays(long long N)
{
    vector<long long>dp(N+1,-1);
    return numberOfWaysHelper(N,dp);
}
int main()
{
    long long n=4;//3

    long long ans=numberOfWays(n);
    cout<<ans<<endl;
    return 0;
}

