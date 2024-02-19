#include<bits/stdc++.h>
using namespace std;
vector<int> mergeTwoArray(vector<int>a,vector<int>b)
{
    int n=a.size();
    int m=b.size();
    vector<int>ans(n+m);
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])ans[k++]=a[i++];
        else ans[k++]=b[j++];
    }
    while(i<n)ans[k++]=a[i++];
    while(j<m)ans[k++]=b[j++];
    return ans;
}
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    //code here
    vector<int>a;
    for(auto b:arr)
    {
        a=mergeTwoArray(a,b);
    }
    return a;
}
int main()
{
    vector<vector<int>>a={{1,2,3},{4,5,6},{7,8,9}};
    int K=3;

    vector<int>ans=mergeKArrays(a,K);

    for(auto x:ans)cout<<x<<" ";cout<<endl;
    return 0;
}
