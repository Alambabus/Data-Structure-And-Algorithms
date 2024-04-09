#include<bits/stdc++.h>
using namespace std;
int linearSearch(vector<int>&a,int t)
{
    int n=a.size();
    for(int i=0;i<n;i++)
        if(a[i]==t)return i;
    return -1;
}
int main()
{
    vector<int>nums={-1,0,3,5,9,12};
    int target=2;
    int indx=linearSearch(nums,target);
    if(indx!=-1)cout<<indx<<endl;
    else cout<<"Not Found"<<endl;
    return 0;
}
