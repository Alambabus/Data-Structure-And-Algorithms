#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int carFleet(int t, vector<int>& p, vector<int>& s)
{
    vector<pair<int,int>>a;
    int n=s.size();
    for(int i=0;i<n;i++)
    a.push_back({p[i],s[i]});
    sort(a.begin(),a.end());
    vector<float>expTime(n);
    for(int i=0;i<n;i++)
    {
        int currP=a[i].first;
        int currS=a[i].second;
        float timeTeken=(t-currP)/(float)currS;
        expTime[i]=timeTeken;
    }
    stack<float>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top()<=expTime[i])st.pop();
        st.push(expTime[i]);
    }
    return st.size();
}
int main()
{
    int target=12;
    vector<int>position={10,8,0,5,3};
    vector<int>speed={2,4,1,1,3};

    int ans=carFleet(target,position,speed);

    cout<<ans<<endl;

    return 0;
}
