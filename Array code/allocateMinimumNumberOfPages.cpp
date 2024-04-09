#include<bits/stdc++.h>
using namespace std;
int countStudents(int a[],int pages,int n)
{
    int cntStudent=1,readPages=0;
    for(int i=0;i<n;i++)
    {
        if(readPages+a[i]<=pages)
        readPages+=a[i];
        else
        {
            cntStudent++;
            readPages=a[i];
        }
    }
    return cntStudent;
}
int findPages(int A[], int N, int M)
{
    if(M>N)return -1;
    int low=*max_element(A,A+N);
    int high=accumulate(A,A+N,0);
    while(low<=high)
    {
        int mid=(low+high)/2;
        int countStudent=countStudents(A,mid,N);
        if(countStudent>M)low=mid+1;
        else high=mid-1;
    }
    return low;
}
int main()
{
    int a[]={12,34,67,90};
    int n=4,m=2;
    int ans=findPages(a,n,m);
    cout<<ans<<endl;
    return 0;
}
