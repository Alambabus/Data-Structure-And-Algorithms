#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void find_permutationHelper(int idx,string s,int n,vector<string> &ans)
{
        //base case
        if(idx==n)
        {
            ans.push_back(s);
            return ;
        }
        //recursive case
        for(int i=idx;i<n;i++)
        {
            if(i>idx && s[i]==s[idx])continue;
            swap(s[idx],s[i]);
            find_permutationHelper(idx+1,s,n,ans);
        }
}
vector<string>find_permutation(string s)
{
        int n=s.size();
        vector<string>ans;
        sort(s.begin(),s.end());
        find_permutationHelper(0,s,n,ans);
        return ans;
}
int main()
{
    string s="BBB";

    vector<string>ans=find_permutation(s);
    for(auto x:ans)cout<<x<<endl;

    return 0;
}


