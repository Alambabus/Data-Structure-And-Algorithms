#include<bits/stdc++.h>
using namespace std;
bool search(vector<int>& a, int t)
{
    int n=a.size();
    int i=0,j=n-1;
    if(a[i]==t || a[j]==t)return true;
    while(i<j && a[i] == a[j])j--;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(a[mid]==t)return true;
        if(t<a[0])
        {
            if(a[mid]>=a[0] || a[mid]<t)i=mid+1;
            else j=mid-1;
        }
        else
        {
            if(a[mid]>=a[0] && a[mid]<t)i=mid+1;
            else j=mid-1;
        }
    }
    return false;
}
int main()
{
    vector<int>a={2,5,6,0,0,1,2};
    int t=0;
    int chk=search(a,t);
    if(chk)cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
    return 0;
}
