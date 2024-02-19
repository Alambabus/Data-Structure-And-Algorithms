#include<iostream>
#include<algorithm>
using namespace std;
void bubbleSortIterative(int a[], int n)
{
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])swap(a[j],a[j+1]);
        }
}
void bubbleSortRecursive(int a[],int n)
{
    //base case
    if(1==n)return ;
    //recursive case
    for(int j=0;j<n-1;j++)
        if(a[j+1]<a[j])swap(a[j],a[j+1]);
    bubbleSortRecursive(a,n-1);
}
int main()
{
    int a[]={4, 1, 3, 9, 7};
    int n=sizeof(a)/sizeof(a[0]);

    for(auto x:a)cout<<x<<" ";
    cout<<endl;

    //bubbleSortIterative(a,n);
    //for(auto x:a)cout<<x<<" ";
    //cout<<endl;

    bubbleSortRecursive(a,n);
    for(auto x:a)cout<<x<<" ";
    cout<<endl;

    return 0;
}
