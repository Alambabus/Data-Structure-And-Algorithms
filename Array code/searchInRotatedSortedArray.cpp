#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &a,int s,int e,int t)
{
    int i=s,j=e;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(a[mid]==t)return mid;
        if(a[mid]>t)j=mid-1;
        else i=mid+1;
    }
    return -1;
}
int findPivotElement(vector<int> &a,int s,int e)
{
    int i=s,j=e;
    int ans=j;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(a[mid]>=a[0])i=mid+1;
        else {
            ans=mid;
            j=mid-1;
        }
    }
    return ans;
}
int search(vector<int>& a, int t)
{
    int n=a.size();
    if(a[0]<=a[n-1])return binarySearch(a,0,n-1,t);
    int pivotIndx=findPivotElement(a,0,n-1);
    if(t>=a[0])return binarySearch(a,0,pivotIndx-1,t);
    else return binarySearch(a,pivotIndx,n-1,t);
}
int main()
{
    vector<int>nums={4,5,6,7,0,1,2};
    int target=0;
    int ans=search(nums,target);
    cout<<ans<<endl;
    return 0;
}
