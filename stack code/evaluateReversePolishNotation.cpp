#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int evalRPN(vector<string>& tokens)
{
    stack<int>s;
    for(string token:tokens)
    {
        int c=0;
        if(token=="+")
        {
            int b=s.top();
            s.pop();
            int a=s.top();
            s.pop();
            s.push(a+b);
            continue;
        }
        if(token=="*")
        {
            int b=s.top();
            s.pop();
            int a=s.top();
            s.pop();
            s.push(a*b);
            continue;
        }
        if(token=="-")
        {
            int b=s.top();
            s.pop();
            int a=s.top();
            s.pop();
            s.push(a-b);
            continue;
        }
        if(token=="/")
        {
            int b=s.top();
            s.pop();
            int a=s.top();
            s.pop();
            s.push(a/b);
            continue;
        }
        bool isMinus=false;
        for(auto x:token)
        {
            if(x=='-')
            {
                isMinus=true;
                continue;
            }
            c=c*10+(x-'0');
        }
        isMinus?s.push(-c):s.push(c);
    }
    return s.top();
}
int main()
{
    vector<string>s={"4","13","5","/","+"};//{"2","11","+","3","*"};

    int ans=evalRPN(s);
    cout<<ans<<endl;

    return 0;
}
