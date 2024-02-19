#include<bits/stdc++.h>
using namespace std;
bool isPerfectSquare(int sum)
{
    int sqt=sqrt(sum);
    return sum==sqt*sqt;
}
void helper(vector<int>a,int idx,int n,int  &ans)
{
    //base case
    if(n==idx)
    {
        ans++;
        return;
    }
    //recursive case
    for(int j=idx;j<n;j++)
    {
        if(j>idx && a[idx]==a[j])continue;
        swap(a[idx],a[j]);
        if(idx==0 || isPerfectSquare(a[idx]+a[idx-1]))
        helper(a,idx+1,n,ans);
    }
}
int numSquarefulPerms(vector<int>& a)
{
    int n=a.size();
    sort(a.begin(),a.end());
    int ans=0;
    helper(a,0,n,ans);
    return ans;
}
int main()
{
   vector<int>a={1,17,8};

   int ans=numSquarefulPerms(a);
   cout<<ans<<endl;

   return 0;
}
