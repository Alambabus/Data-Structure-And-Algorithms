#include<bits/stdc++.h>
using namespace std;
int totalPossibleSubArray(vector<int> &a,int k)
{
    int n=a.size();
    map<int,int>m;
    int i=0,j=0,ans=0;
    while(j<n)
    {
        m[a[j]]++;
        while(m.size()>k)
        {
            m[a[i]]--;
            if(m[a[i]]==0)m.erase(a[i]);
            i++;
        }
        ans+=j-i+1;
        j++;
    }
    return ans;
}
int subarraysWithKDistinct(vector<int>& a, int k)
{
    int atMostK=totalPossibleSubArray(a,k);
    int atMostKMinusOne=totalPossibleSubArray(a,k-1);
    return atMostK-atMostKMinusOne;
}
int main()
{
    vector<int>a={1,2,1,2,3};
    int k=2;
    int ans=subarraysWithKDistinct(a,k);
    cout<<ans<<endl;
    return 0;
}
