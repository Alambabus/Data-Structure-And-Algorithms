#include<bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int>& a)
{
    int n=a.size();
    for(int i=0;i<n;i++)if(a[i]<=0)a[i]=n+1;
    for(int i=0;i<n;i++)
    {
        if(abs(a[i])-1<n && a[abs(a[i])-1]<0)continue;
        if(abs(a[i])-1<n)a[abs(a[i])-1]*=-1;
    }
    for(int i=0;i<n;i++)
    if(a[i]>=0)return i+1;
    return n+1;
}

int main()
{
    vector<int>a={3,4,-1,1};

    int ans=firstMissingPositive(a);

    cout<<ans<<endl;
    return 0;
}
