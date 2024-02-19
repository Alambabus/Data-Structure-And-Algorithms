#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string removeDuplicatesUsingString(string s)
{
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            char x=s[i];
            if(!ans.empty() && ans.back() == x)
            {
                ans.pop_back();
                continue;
            }
            ans.push_back(x);
        }
        return ans;
}

string removeDuplicatesUsingStack(string s)
{
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            char x=s[i];
            if(!st.empty() && x==st.top())
            {
                while(!st.empty() && x==st.top())st.pop();
                continue;
            }
            st.push(x);
        }
        string ans="";
        while(!st.empty())
        {
           ans+=st.top();
           st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
int main()
{

    string st="azxxzy";
    //string st="abbaca";

    string ans=removeDuplicatesUsingString(st);
    cout<<ans<<endl;

    string ans1=removeDuplicatesUsingStack(st);
    cout<<ans1<<endl;

    return 0;
}
