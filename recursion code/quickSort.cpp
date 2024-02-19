#include<iostream>
using namespace std;
void quickSort(int arr[],int low,int high)
{
        // base case
        if(low>=high)return ;
        //recursive case
        int pivot=arr[high];
        int idx=-1;
        for(int i=low;i<=high;i++)
        if(arr[i]<=pivot)swap(arr[++idx],arr[i]);
        quickSort(arr,low,idx-1);
        quickSort(arr,idx+1,high);
}
int main()
{
    int a[]={4, 1, 3, 9, 7};
    int n=sizeof(a)/sizeof(a[0]);

    for(auto x:a)cout<<x<<" ";
    cout<<endl;

    quickSort(a,0,n-1);
    for(auto x:a)cout<<x<<" ";
    cout<<endl;

    return 0;
}
