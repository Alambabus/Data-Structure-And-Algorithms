#include<bits/stdc++.h>
using namespace std;
void productExceptSelf(int a[],int n)
{
        vector<int>left(n);
        left[0]=1;
        for(int i=1;i<n;i++)
        {
            left[i]=left[i-1]*a[i-1];
        }
        vector<int>right(n);
        right[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            right[i]=right[i+1]*a[i+1];
        }
        for(int i=0;i<n;i++)
        a[i]=left[i]*right[i];
}
int main()
{
    int a[]={1,2,3,4};
    productExceptSelf(a,4);
    for(int i=0;i<4;i++)cout<<a[i]<<" ";cout<<endl;
    return 0;
}
