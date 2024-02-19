#include<bits/stdc++.h>
using namespace std;
bool isFit(map<char,int> &mps,map<char,int> &mpt)
{
    for(auto x:mpt)
    {
        if(x.second>mps[x.first])return false;
    }
    return true;
}
string minWindow(string s, string t)
{
    map<char,int>mpt;
    for(auto x:t)mpt[x]++;
    int i=0,j=0,startIndex=0;
    int ans=INT_MAX;
    map<char,int>mps;
    int n=s.size();
    while(j<n)
    {
        while(j<n && !isFit(mps,mpt))mps[s[j++]]++;
        while(isFit(mps,mpt))
        {
            if(ans>j-i)
            {
                ans=j-i;
                startIndex=i;
            }
            mps[s[i++]]--;
        }
    }
    if(ans==INT_MAX)return "";
    string res=s.substr(startIndex,ans);
    return res;
}

int main()
{
    string s="ADOBECODEBANC";
    string t="ABC";

    string ans=minWindow(s,t);

    cout<<ans<<endl;
    return 0;
}
