#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
string removeKdigits(string num, int k)
{
    int n=num.size();
    stack<char>s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && k>0 && s.top()>num[i])
        {
            k--;
            s.pop();
        }
        s.push(num[i]);
    }
    string ans="";
    while(!s.empty())
    {
        ans+=s.top();
        s.pop();
    }
    reverse(ans.begin(),ans.end());
    while(ans.size()>0 && k>0)
    {
        ans.pop_back();
        k--;
    }
    int i=0;
    while(ans.size()>0 && ans[i]=='0')i++;
    ans=ans.substr(i);
    return ans.size()>0?ans:"0";
}
int main()
{
    string num="1432219";
    int k=3;

    string ans=removeKdigits(num,k);
    cout<<ans<<endl;

    return 0;
}
