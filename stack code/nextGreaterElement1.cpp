#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextGreaterElement1(int n1[],int n2[],int sz1,int sz2)
{
        vector<int>ans;
        stack<int>s;
        unordered_map<int,int>m;
        for(int i=sz2-1;i>=0;i--)
        {
            while(!s.empty() && s.top()<=n2[i])s.pop();
            m[n2[i]]=s.empty()?-1:s.top();
            s.push(n2[i]);
        }
        for(int i=0;i<sz1;i++)
        {
            ans.push_back(m[n1[i]]);
        }
     return ans;
    }
int main()
{
    int n1[]={4,1,2};
    int n2[]={1,3,4,2};
    int sz1=sizeof(n1)/sizeof(n1[0]);
    int sz2=sizeof(n2)/sizeof(n2[0]);

    vector<int>ans=nextGreaterElement1(n1,n2,sz1,sz2);
    for(auto x:ans)cout<<x<<" ";

    return 0;
}
