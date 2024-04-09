#include<bits/stdc++.h>
using namespace std;
void findTwoSum(vector<int>& a,int i,int t,set<vector<int>> &ans)
{
    int n=a.size();
    int j=n-1;
    while(i<j)
    {
        int sum=a[i]+a[j];
        if(t+sum==0)
        {
            ans.insert({t,a[i],a[j]});
        }
        if(t+sum<0)i++;
        else j--;
    }
}
vector<vector<int>> threeSum(vector<int>& a)
{
    sort(a.begin(),a.end());
    int n=a.size();
    set<vector<int>>ans;
    for(int i=0;i<n;i++)
    {
        findTwoSum(a,i+1,a[i],ans);
    }
    vector<vector<int>>finalAns;
    for(auto x:ans)
    {
        finalAns.push_back(x);
    }
    return finalAns;
}
int main()
{
    vector<int>nums={-1,0,1,2,-1,-4};
    vector<vector<int>>ans=threeSum(nums);
    for(auto x:ans)
    {

        for(auto y:x)cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}
