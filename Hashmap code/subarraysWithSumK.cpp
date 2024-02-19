#include<bits/stdc++.h>
using namespace std;
int findSubArraySum(int a[], int n, int k)
{
    // code here
    int cSum=0;
    unordered_map<int,int>m;
    m[0]=1;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cSum+=a[i];
        ans+=m[cSum-k];
        m[cSum]++;
    }
    return ans;
}

int main()
{
    int n=5;
    int a[]={10 , 2, -2, -20, 10};
    int k=-10;

    int ans=findSubArraySum(a,n,k);

    cout<<ans<<endl;
    return 0;
}
