#include<iostream>
#include<stack>
using namespace std;
bool isMatched(char a,char b){
  return ((a==')' && b=='(') ||
         (a=='}' && b=='{') ||
         (a==']' && b=='['));
}
bool isBalanced(string &st)
{
    int n=st.size();
    stack<char>s;
    for(int i=0;i<n;i++)
    {
        if(st[i]=='(' || st[i]=='[' || st[i]=='{')s.push(st[i]);
        else if(st[i]==')' || st[i]=='}' || st[i]==']')
        {
            if(s.empty())return false;
            else if(!isMatched(st[i],s.top()))return false;
            else s.pop();
        }
    }
    return s.empty();
}
int main()
{
    //Input: "([])"    //Input: "((())"
    //Output: true     ////Output: flase

    string st="((())";
    bool ans=isBalanced(st);
    if(ans)cout<<"True";
    else cout<<"False";
    return 0;
}
