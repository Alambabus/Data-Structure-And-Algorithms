#include<iostream>
using namespace std;
int minimumAddToMakeValidParenthesis(string s)
{
     int n=s.size();
        int cnt=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')cnt++;
            else if(cnt==0)ans++;
            else cnt--;
        }
        return ans+cnt;
}
int main()
{
    string s="())";
    //string s="(((";

    int ans=minimumAddToMakeValidParenthesis(s);
    cout<<ans<<endl;
    return 0;
}

