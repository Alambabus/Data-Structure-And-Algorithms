#include<bits/stdc++.h>
using namespace std;
int partitionDisjoint(vector<int>& a)
{
    int n=a.size();
    int leftMax[n];
    leftMax[0]=a[0];
    for(int i=1;i<n;i++)
    leftMax[i]=max(leftMax[i-1],a[i]);
    int rightMin[n];
    rightMin[n-1]=INT_MAX;
    for(int i=n-2;i>=0;i--)
    rightMin[i]=min(rightMin[i+1],a[i+1]);
    for(int i=0;i<n;i++)
    if(leftMax[i]<=rightMin[i])
    return i+1;
    return -1;
}
int main()
{
    vector<int>a={5,0,3,8,6};
    int ans=partitionDisjoint(a);
    cout<<ans<<endl;
    return 0;
}
