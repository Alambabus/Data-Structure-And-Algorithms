#include<bits/stdc++.h>
using namespace std;
bool hasArrayTwoCandidates(int arr[], int n, int x)
{
    // code here
    unordered_map<int,bool>m;
    for(int i=0;i<n;i++)
    {
        if(m[x-arr[i]])return true;
        m[arr[i]]=true;
    }
    return false;
}

int main()
{
    int n=6,x=16;
    int a[]={1, 4, 45, 6, 10, 8};

    bool chk=hasArrayTwoCandidates(a,n,x);
    if(chk)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
