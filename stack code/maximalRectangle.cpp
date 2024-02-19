#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
vector<int> nextSmaller(vector<int> &h)
{
    stack<int>s;
    int n=h.size();
    vector<int>ans;
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && h[s.top()]>=h[i])s.pop();
        ans.push_back(s.empty()?n:s.top());
        s.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
vector<int> previousSmaller(vector<int> &h)
{
    stack<int>s;
    int n=h.size();
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && h[s.top()]>=h[i])s.pop();
        ans.push_back(s.empty()?-1:s.top());
        s.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int>& h)
{
    int n=h.size();
    vector<int>left=previousSmaller(h);
    vector<int>right=nextSmaller(h);
    int ans=0;
    for(int i=0;i<n;i++)
    ans=max(ans,((right[i]-left[i]-1)*h[i]));
    return ans;
}
int maximalRectangle(vector<vector<char>>& m)
{
    vector<int>h(m[0].size(),0);
    int ans=0;
    for(auto x:m)
    {
        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='0')h[i]=0;
            else h[i]++;
        }
            ans=max(ans,largestRectangleArea(h));
    }
    return ans;
}
int main()
{
    vector<vector<char>>matrixes={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    int ans=maximalRectangle(matrixes);
    cout<<ans<<endl;
    return 0;
}
