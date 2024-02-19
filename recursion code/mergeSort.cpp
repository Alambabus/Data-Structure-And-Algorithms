#include<iostream>
#include<algorithm>
using namespace std;
void merge(int a[], int l,int mid,int r)
{
        int t[r-l+1];
        int i=l,j=mid+1;
        int k=0;
        while(i<=mid && j<=r)
        {
            if(a[i]<a[j])t[k++]=a[i++];
            else t[k++]=a[j++];
        }
        while(i<=mid)t[k++]=a[i++];
        while(j<=r)t[k++]=a[j++];
        k=0;
        for(i=l;i<=r;i++)a[i]=t[k++];

}
void mergeSort(int a[],int l,int r)
{
    //base case
    if(l>=r)return ;
    //recursive case
    int mid=(l+r)/2;
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);
    merge(a,l,mid,r);
}
int main()
{
    int a[]={4, 1, 3, 9, 7};
    int n=sizeof(a)/sizeof(a[0]);

    for(auto x:a)cout<<x<<" ";
    cout<<endl;

    mergeSort(a,0,n-1);
    for(auto x:a)cout<<x<<" ";
    cout<<endl;

    return 0;
}
