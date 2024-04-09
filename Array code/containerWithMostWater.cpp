#include<bits/stdc++.h>
using namespace std;
int maxArea(int a[],int n)
{
    int finalAns=0;
    int i=0,j=n-1;
    while(i<j)
    {
        finalAns=max((min(a[i],a[j])*(j-i)),finalAns);
        if(a[i]<a[j])i++;
        else j--;
    }
    return finalAns;
}
int main()
{
    int height[]={1,8,6,2,5,4,8,3,7};
    int ans=maxArea(height,9);
    cout<<ans<<endl;
    return 0;
}
