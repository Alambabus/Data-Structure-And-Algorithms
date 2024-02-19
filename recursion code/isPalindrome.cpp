#include<iostream>
using namespace std;
bool isPalindromeIterative(int a[],int n)
{
    int i=0,j=n-1;
    while(i<j)
    {
        if(a[i] != a[j])
            return false;
        i++;
        j--;
    }
    return true;
}
bool isPalindromeRecursive(int a[],int i,int j)
{
    //base case
    if(i>j)return true;
    if(a[i] != a[j])return false;
    if(i==j)return true;
    //recursive case
    return isPalindromeRecursive(a,i+1,j-1);
}
int main()
{
    int a[]={1,2,3,3,2,1};
    int n=sizeof(a)/sizeof(a[0]);

    //int a[]={1,2,4,2,1};
    //int n=sizeof(a)/sizeof(a[0]);

    //int a[]={1,2,3,4,5,6};
    //int n=sizeof(a)/sizeof(a[0]);

    bool ans=isPalindromeIterative(a,n);
    if(ans)cout<<"True"<<endl;
    else cout<<"False"<<endl;

    bool ans1=isPalindromeRecursive(a,0,n-1);
    if(ans1)cout<<"True"<<endl;
    else cout<<"False"<<endl;

    return 0;
}
