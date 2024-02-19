#include<bits/stdc++.h>
using namespace std;
bool subArrayExists(int a[], int n)
{
    //Your code here
    int cSum[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum==0)return true;
        cSum[i]=sum;
    }
    unordered_map<int,bool>m;
    for(int i=0;i<n;i++)
    {
        if(m[cSum[i]])return true;
        m[cSum[i]]=true;
    }
    return false;
}

int main()
{
    int n=5;
    int a[]={4,2,-3,1,6};

    bool chk=subArrayExists(a,n);
    if(chk)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
