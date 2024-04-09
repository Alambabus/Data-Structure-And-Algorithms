#include<bits/stdc++.h>
using namespace std;
bool canWePlaced(vector<int> &p,int dis,int m)
{
    int n=p.size();
    int countCow=1,last=p[0];
    for(int i=1;i<n;i++)
    {
        if(p[i]-last>=dis)
        {
            last=p[i];
            countCow++;
        }
        if(countCow>=m)return true;
    }
    return false;
}

int maxDistance(vector<int>& p, int m)
{
    int n=p.size();
    sort(p.begin(),p.end());
    int low=1,high=p[n-1]-p[0];
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(canWePlaced(p,mid,m))low=mid+1;
        else high=mid-1;
    }
    return high;
}
int main()
{
    vector<int>position={1,2,3,4,7};
    int m=3;
    int ans=maxDistance(position,m);
    cout<<ans<<endl;
    return 0;
}
