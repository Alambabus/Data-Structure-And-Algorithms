#include<bits/stdc++.h>
using namespace std;
void rotate(int a[], int k,int n)
{
    k%=n;
    reverse(a,a-k+n);
    reverse(a-k+n,a+n);
    reverse(a,a+n);
}
int main()
{
    int a[]={1,2,3,4,5,6,7};
    int k=3;
    rotate(a,k,7);
    for(int i=0;i<7;i++)cout<<a[i]<<" ";cout<<endl;
    return 0;
}
