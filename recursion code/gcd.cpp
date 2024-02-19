#include<iostream>
#include<algorithm>
using namespace std;
void findGcd(int a,int b)
{
    while(a)
    {
        int t=a;
        a=b%a;
        b=t;
        if(a==0)
        {
            cout<<b<<endl;
            break;
        }
    }

}
int findGcdRecursive(int a,int b)
{
    //base case
    if(a==0)return b;
    //recursive case
    return findGcdRecursive(b%a,a);
}
void findGcdUsingSTLFunction(int a,int b)
{
    cout<<__gcd(a,b)<<endl;

}
int main()
{
    //int a=1,b=0;
    int a=12,b=20;

    findGcdUsingSTLFunction(a,b);
    findGcdIterative(a,b);
    int ans=findGcdRecursive(a,b);
    cout<<ans<<endl;
    return 0;
}
