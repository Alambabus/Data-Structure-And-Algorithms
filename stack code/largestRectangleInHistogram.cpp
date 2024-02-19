#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
vector<int> nextSmaller(int h[],int n)
{
        stack<int>s;
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
vector<int> previousSmaller(int h[],int n)
{
        stack<int>s;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && h[s.top()]>=h[i])s.pop();
            ans.push_back(s.empty()?-1:s.top());
            s.push(i);
        }
        return ans;
}
int largestRectangleArea(int h[],int n)
{
        vector<int>left=previousSmaller(h,n);
        vector<int>right=nextSmaller(h,n);
        int ans=0;
        for(int i=0;i<n;i++)
        ans=max(ans,((right[i]-left[i]-1)*h[i]));
        return ans;
}

int main()
{
    int h[]={2,1,5,6,2,3};
    int n=sizeof(h)/sizeof(h[0]);

    int ans=largestRectangleArea(h,n);
    cout<<ans<<endl;
    return 0;
}
