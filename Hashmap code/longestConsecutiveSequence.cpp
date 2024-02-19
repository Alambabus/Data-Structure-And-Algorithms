#include<bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int>& a)
{
    int n=a.size();
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
    {
        int node=a[i];
        if(m.count(node))continue;
        if(m.count(node-1) && m.count(node+1))
        {
            int sz=m[node-1]+1+m[node+1];
            m[node+m[node+1]]=sz;
            m[node-m[node-1]]=sz;
            m[node]=1;
        }
        else if(m.count(node-1))
        {
            int sz=m[node-1]+1;
            m[node-sz+1]=sz;
            m[node]=sz;
        }
        else if(m.count(node+1))
        {
            int sz=1+m[node+1];
            m[node]=sz;
            m[node+sz-1]=sz;
        }
        else m[node]=1;
    }
    int ans=0;
    for(auto x:m)
    ans=max(ans,x.second);
    return ans;
}

int main()
{
    vector<int>a={100,4,200,1,3,2};

    int ans=longestConsecutive(a);

    cout<<ans<<endl;
    return 0;
}
