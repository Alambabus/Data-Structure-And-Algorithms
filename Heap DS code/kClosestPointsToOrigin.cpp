#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& p, int k)
{
    vector<vector<int>>ans;
    multimap<int,pair<int,int>>m;
    int n=p.size();
    for(int i=0;i<n;i++)
    {
        int x=p[i][0];
        int y=p[i][1];
        m.insert({x*x+y*y,{x,y}});
    }
    for(auto x:m)
    {
        ans.push_back({x.second.first,x.second.second});
        k--;
        if(k==0)break;
    }
    return ans;
}

int main()
{
    vector<vector<int>>a={{3,3},{5,-1},{-2,4}};

    int k=2;

    vector<vector<int>>ans=kClosest(a,k);

    for(auto x:ans)
    {
        for(auto y:x)cout<<y<<" ";cout<<endl;
    }
    return 0;
}
