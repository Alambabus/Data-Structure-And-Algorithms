#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
string removeDuplicateLetters(string s)
{
    int n=s.size();
    vector<int>fre(26,0);
    for(int i=0;i<n;i++)fre[s[i]-'a']++;
    vector<bool>included(26,false);
    string ans="";
    for(int i=0;i<n;i++)
    {
        char x=s[i];
        if(included[s[i]-'a'])
        {
            fre[x-'a']--;
            continue;
        }
        while(ans.size()>0 && fre[ans.back()-'a']>0 && ans.back()>x)
        {
            included[ans.back()-'a']=false;
            ans.pop_back();
        }
        ans+=x;
        included[x-'a']=true;
        fre[x-'a']--;
    }
    return ans;
}
int main()
{
    string s="cbacdcbc";
    string ans=removeDuplicateLetters(s);
    cout<<ans<<endl;
    return 0;
}
