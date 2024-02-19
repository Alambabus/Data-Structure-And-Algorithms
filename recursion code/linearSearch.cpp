#include<iostream>
using namespace std;
int linearSearchIterative(int a[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)return i;
    }
    return -1;
}
int linearSearchRecursive(int a[],int i,int n,int key)
{
    //base case
    if(i==n)return -1;
    if(a[i]==key)return i;
    //recursive case
    return linearSearchRecursive(a,i+1,n,key);
}
int main()
{
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);

    int key=5;
    int ans=linearSearchIterative(a,n,key);
    if(ans!=-1)cout<<"Index: "<<ans<<endl;
    else cout<<"Not Found in array."<<endl;

    int ans1=linearSearchRecursive(a,0,n,key);
    if(ans1!=-1)cout<<"Index: "<<ans1<<endl;
    else cout<<"Not Found in array."<<endl;

    return 0;
}
