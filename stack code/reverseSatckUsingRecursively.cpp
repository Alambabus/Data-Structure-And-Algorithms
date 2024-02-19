#include<iostream>
#include<stack>
using namespace std;
void reverseHelper(stack<int>&s,int t)
{
        //base case
        if(s.empty())
        {
            s.push(t);
            return ;
        }
        //recursive case
        int temp=s.top();
        s.pop();
        reverseHelper(s,t);
        s.push(temp);
}

void Reverse(stack<int> &s)
{
        //base case
        if(s.empty())return ;
        //recursive case
        int t=s.top();
        s.pop();
        Reverse(s);
        reverseHelper(s,t);
}
void printStack(stack<int>s)
{
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
}
int main()
{
    stack<int>s;
    for(int i=10;i<=50;i+=10)
        s.push(i);

    printStack(s);

    Reverse(s);

    printStack(s);

    return 0;
}
