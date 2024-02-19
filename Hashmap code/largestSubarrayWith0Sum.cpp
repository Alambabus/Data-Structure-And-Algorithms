#include<bits/stdc++.h>
using namespace std;
int maxLen(int A[], int n)
{
    // Your code here
    int ans=0;
    vector<int>cSum(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        cSum[i]=sum;
    }
    unordered_map<int,int>m;
    m[0]=-1;
    for(int i=0;i<n;i++)
    {
        if(!m.count(cSum[i]))m[cSum[i]]=i;
       else ans=max(ans,i-m[cSum[i]]);
    }
    return ans;
}

int main()
{
    int n=8;
    int a[]={15,-2,2,-8,1,7,10,23};

    int ans=maxLen(a,n);
    cout<<ans<<endl;
    return 0;
}
