#include<iostream>
using namespace std;
string minimumRemoveToMakeValidParenthesis(string s)
{
     int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            char x=s[i];
            if(x=='(')cnt++;
            else if(x==')')
            {
                if(cnt==0)s[i]='#';
                else cnt--;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(cnt>0 && s[i]=='(')
            {
                s[i]='#';
                cnt--;
            }
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(s[i]=='#')continue;
            ans+=s[i];
        }
        return ans;
}
int main()
{
    //string s="lee(t(c)o)de)";
    //string s="a)b(c)d";
    string s="))((";

    string ans=minimumRemoveToMakeValidParenthesis(s);
    cout<<ans<<endl;
    return 0;
}
