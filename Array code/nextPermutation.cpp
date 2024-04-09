#include<bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int>& a)
{
    int n=a.size();
    int j=n-2;
    while(j>=0 && a[j]>=a[j+1])j--;
    if(j<0)
    {
        sort(a.begin(),a.end());
        return ;
    }
    sort(a.begin()+j+1,a.end());
    int k=j+1;
    while(k<n)
    {
        if(a[k]>a[j])
        {
            swap(a[k],a[j]);
            break;
        }
        k++;
    }
}
int main()
{
    vector<int>a={1,7,6,3,5,4,2,1};
    nextPermutation(a);
    for(auto x:a)cout<<x<<" ";
    return 0;
}
