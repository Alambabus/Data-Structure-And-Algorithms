#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int getPriority(char ch)
{
    if(ch == '^')return 3;
    if(ch == '*' || ch == '/')return 2;
    if(ch == '+' || ch == '-')return 1;
    return 0;
}
string infixToPostfix(string s) {
    // Your code here
    stack<char>st;
    int n=s.size();
    string ans="";
    for(int i=0;i<n;i++)
    {
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9')
        {
            ans+=s[i];
            continue;
        }
        if(s[i]=='(' ||  st.empty())
        {
            st.push(s[i]);
            continue;
        }
        if(s[i]==')')
        {
            while(!st.empty() && st.top() != '(')
            {
                ans+=st.top();
                st.pop();
            }
            if(!st.empty())
            st.pop();
            continue;
        }
        if(getPriority(st.top())<getPriority(s[i]))
        {
            st.push(s[i]);
        }
        else
        {
            while(!st.empty() && getPriority(st.top())>=getPriority(s[i]))
            {
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main()
{

   string infix="a+b*(c^d-e)^(f+g*h)-i";

   string postfix=infixToPostfix(infix);
   cout<<postfix<<endl;

    return 0;
}
