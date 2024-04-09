#include<bits/stdc++.h>
using namespace std;
bool canWePlaced(vector<int> &stalls,int dis,int k,int n)
{
    int cntCow=1,last=stalls[0];
    for(int i=1;i<n;i++)
    {
        if(stalls[i]-last>=dis)
        {
            cntCow++;
            last=stalls[i];
        }
        if(cntCow>=k)return true;
    }
    return false;
}
int solve(int n, int k, vector<int> &stalls)
{
    sort(stalls.begin(),stalls.end());
    int low=1,high=stalls[n-1]-stalls[0];
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(canWePlaced(stalls,mid,k,n))low=mid+1;
        else high=mid-1;
    }
    return high;
}
int main()
{
    vector<int>stalls={1,2,4,8,9};
    int k=3;
    int ans=solve(stalls.size(),k,stalls);
    cout<<ans<<endl;
    return 0;
}
