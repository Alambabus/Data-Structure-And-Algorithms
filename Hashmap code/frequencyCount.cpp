#include<bits/stdc++.h>
using namespace std;
void freqCount(int a[],int n)
{
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)m[a[i]]++;

    for(auto x:m)cout<<x.first<<"->"<<x.second<<endl;
}
int main()
{
    int a[]={1,1,2,3,3,3,4,5,5,6,6,6,6,7};
    int n=sizeof(a)/sizeof(a[0]);

    freqCount(a,n);

    return 0;
}
