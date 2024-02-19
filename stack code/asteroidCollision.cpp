#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> asteroidCollision(vector<int>& a)
{
    int n=a.size();
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=0)
        {
            s.push(a[i]);
            continue;
        }
        if(a[i]<0 && (s.empty() || s.top()<0))s.push(a[i]);
        else
        {
                while(!s.empty() && s.top()>=0 && abs(a[i])>s.top())s.pop();
                if(!s.empty() && s.top()<0)s.push(a[i]);
                else if(s.empty() && a[i]<0)s.push(a[i]);
                else if(abs(a[i])==s.top())s.pop();
        }
    }
    vector<int>ans(s.size());
    for(int i=s.size()-1;i>=0;i--)
    {
        ans[i]=s.top();
        s.pop();
    }
    return ans;
}
int main()
{
    vector<int>a={5,10,-5};

    vector<int>ans=asteroidCollision(a);

    for(auto x:ans)cout<<x<<" ";

    return 0;
}
