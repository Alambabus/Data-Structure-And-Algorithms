#include<bits/stdc++.h>
using namespace std;
int findMinRotatedSoertedArray(vector<int> &a,int s,int e)
{
            int i=s,j=e;
            int ans=a[j];
            if(a[i]<a[j])return a[i];
            while(i<=j)
            {
                int mid=(i+j)/2;
                if(a[mid]>=a[s])i=mid+1;
                else
                {
                ans=a[mid];
                j=mid-1;
                }
            }
            return ans;
}
int findMin(vector<int>& a)
{
    int n=a.size();
    if(a[0]<a[n-1])return a[0];
    int i=0,j=n-1;
    while(i<j && a[i]==a[j])j--;
    return findMinRotatedSoertedArray(a,i,j);
}
int main()
{
    vector<int>nums={2,2,2,0,1};
    int ans=findMin(nums);
    cout<<ans<<endl;
    return 0;
}
