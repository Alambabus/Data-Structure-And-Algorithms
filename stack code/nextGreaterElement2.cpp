#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextGreaterElement2(int a[],int n)
{
       vector<int>ans;
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && a[i]>=s.top())s.pop();
            s.push(a[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && a[i]>=s.top())s.pop();
            ans.push_back(s.empty()?-1:s.top());
            s.push(a[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
int main()
{
    int a[]={1,2,3,4,3};
    int n=sizeof(a)/sizeof(a[0]);

    vector<int>ans=nextGreaterElement2(a,n);
    for(auto x:ans)cout<<x<<" ";

    return 0;
}

