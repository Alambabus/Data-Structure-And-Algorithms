#include<iostream>
using namespace std;
int binarySearchIterative(int a[],int n,int key)
{
    int i=0,j=n-1;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(a[mid]==key)return mid;
        if(a[mid]<key)i=mid+1;
        else j=mid-1;
    }
    return -1;
}
int binarySearchRecursive(int a[],int i,int j,int key)
{
    //base case
    if(i>j)return -1;
    int mid=(i+j)/2;
    if(a[mid]==key)return mid;
    //recursive case
    if(a[mid]<key)
        return binarySearchRecursive(a,mid+1,j,key);
    else
        return binarySearchRecursive(a,i,mid-1,key);
}
int main()
{
    int a[]={1,2,3,4,5,6};
    int n=sizeof(a)/sizeof(a[0]);

    int key=9;

    int ans=binarySearchIterative(a,n,key);
    if(ans != -1)cout<<ans<<endl;
    else cout<<"Not Found in array"<<endl;

    int ans1=binarySearchRecursive(a,0,n-1,key);
    if(ans1 != -1)cout<<ans1<<endl;
    else cout<<"Not Found in array"<<endl;


    return 0;
}

