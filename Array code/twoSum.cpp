#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& a, int t)
{
    int n=a.size();
    pair<int,int>p[n];
    for(int i=0;i<n;i++)
    {
        p[i]={a[i],i};
    }
    sort(p,p+n);
    int i=0,j=n-1;
    while(i<j)
    {
        if(p[i].first+p[j].first==t)
            return {p[i].second,p[j].second};
        else if(p[i].first+p[j].first<t)i++;
        else j--;
    }
    return {-1,-1};
}
int main()
{
    vector<int>nums={2,7,11,15};
    int target=9;
    vector<int>ans=twoSum(nums,target);
    for(auto x:ans)cout<<x<<" ";cout<<endl;
    return 0;
}
