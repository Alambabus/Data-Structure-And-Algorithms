#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int>& a)
{
    int n=a.size();
    if(a[0]<=a[n-1])return a[0];
    int i=0,j=n-1;
    int ans=a[n-1];
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(a[mid]>=a[0])i=mid+1;
        else
        {
            ans=a[mid];
            j=mid-1;
        }
    }
    return ans;
}
int main()
{
    vector<int>nums={3,4,5,1,2};
    int ans=findMin(nums);
    cout<<ans<<endl;
    return 0;
}
