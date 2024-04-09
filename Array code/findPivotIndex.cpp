#include<bits/stdc++.h>
using namespace std;
int pivotIndex(vector<int>& a)
{
    int n=a.size();
    int leftSum[n],rightSum[n];
    leftSum[0]=a[0];
    for(int i=1;i<n;i++)
    leftSum[i]=leftSum[i-1]+a[i];
    rightSum[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    rightSum[i]=rightSum[i+1]+a[i];
    for(int i=0;i<n;i++)
    if(leftSum[i]==rightSum[i])return i;
    return -1;
}
int main()
{
    vector<int>nums={1,7,3,6,5,6};
    int ans=pivotIndex(nums);
    cout<<ans<<endl;
    return 0;
}

