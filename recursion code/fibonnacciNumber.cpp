#include<iostream>
using namespace std;
int fibonnacciNumberIterative(int n)
{
    if(n==1)return 0;
    if(n==2)return 1;
    int first=0,second=1;
    for(int i=3;i<=n;i++)
    {
        int third=first+second;
        first=second;
        second=third;
    }
    return second;
}
int fibonnacciNumberRecursive(int n)
{
    //base case
    if(n==1)return 0;
    if(n==2 || n==3)return 1;
    //recursive case
    return fibonnacciNumberRecursive(n-1)+fibonnacciNumberRecursive(n-2);
}
int main()
{
    int n=10;

    int ans=fibonnacciNumberIterative(n);
    cout<<ans<<endl;

    int ans1=fibonnacciNumberRecursive(n);
    cout<<ans1<<endl;
    return 0;
}
