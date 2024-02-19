#include<iostream>
#include<stack>
using namespace std;
int scoreOfParenthesis(string s)
{
     int n=s.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
               if(s[i]=='(')st.push(0);
               else
               {
                   int childScor=0;
                   while(st.top() !=0 )
                   {
                       childScor+=st.top();
                       st.pop();
                   }
                   st.pop();
                   if(childScor==0)st.push(1);
                   else st.push(childScor*2);
               }
        }
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
}
int main()
{
    //string s="()()";
    string s="((()))";

    int ans=scoreOfParenthesis(s);
    cout<<ans<<endl;
    return 0;
}

