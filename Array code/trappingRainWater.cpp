#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>& h)
{
    int n=h.size();
    int lMax[n];
    lMax[0]=h[0];
    for(int i=1;i<n;i++)
    lMax[i]=max(lMax[i-1],h[i]);
    int rMax[n];
    rMax[n-1]=h[n-1];
    for(int i=n-2;i>=0;i--)
    rMax[i]=max(rMax[i+1],h[i]);
    int ans=0;
    for(int i=0;i<n;i++)
    ans+=min(lMax[i],rMax[i])-h[i];
    return ans;
}
int main()
{
    vector<int>h={0,1,0,2,1,0,1,3,2,1,2,1};
    int ans=trap(h);
    cout<<ans<<endl;
    return 0;
}
