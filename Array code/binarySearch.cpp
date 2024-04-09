#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>& a, int t)
{
    int n=a.size();
    int i=0,j=n-1;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(a[mid]==t)return mid;
        if(a[mid]<t)i=mid+1;
        else j=mid-1;
    }
    return -1;
}
int main()
{
    vector<int>nums={-1,0,3,5,9,12};
    int target=9;
    int indx=binarySearch(nums,target);
    if(indx!=-1)cout<<indx<<endl;
    else cout<<"Not Found"<<endl;
    return 0;
}
