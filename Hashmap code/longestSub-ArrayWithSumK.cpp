#include<bits/stdc++.h>
using namespace std;
int lenOfLongSubarr(int a[],  int n, int k)
{
    // Complete the function
    vector<int>cSum(n);
    int sum=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        cSum[i]=sum;
    }
    unordered_map<int,int>m;
    m[0]=-1;
    for(int i=0;i<n;i++)
    {
        if(m.count(cSum[i]-k)) ans=max(ans,i-m[cSum[i]-k]);
        if(!m.count(cSum[i]))m[cSum[i]]=i;
    }
    return ans;
}

int main()
{
    int n=6;
    int a[]={10, 5, 2, 7, 1, 9};
    int k=15;

    int ans=lenOfLongSubarr(a,n,k);

    cout<<ans<<endl;
    return 0;
}
