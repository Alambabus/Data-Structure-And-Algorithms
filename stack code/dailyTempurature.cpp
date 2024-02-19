#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
vector<int> dailyTemparature(int temp[],int n)
{
        stack<int>s;
        vector<int>ans;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && temp[s.top()]<=temp[i])s.pop();
            ans.push_back(s.empty()?0:s.top()-i);
            s.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
int main()
{
    int a[]={73,74,75,71,69,72,76,73};
    int n=sizeof(a)/sizeof(a[0]);

    vector<int>ans=dailyTemparature(a,n);
    for(auto x:ans)cout<<x<<" ";
    return 0;
}
