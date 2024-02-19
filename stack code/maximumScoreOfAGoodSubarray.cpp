#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
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
int maximumScore(vector<int>& nums, int k)
{
    int n=nums.size();
    vector<int>left=previousSmaller(nums);
    vector<int>right=nextSmaller(nums);
    int score=0;
    for(int i=0;i<n;i++)
    {
        int l=left[i];
        int r=right[i];
        if(l+1<=k && r-1>=k)
        {
            score=max(score,nums[i]*(r-l-1));
        }
    }
    return score;
}
int main()
{
    vector<int>nums={1,4,3,7,4,5};
    int k=3;

    int score=maximumScore(nums,k);
    cout<<score<<endl;

    return 0;
}
