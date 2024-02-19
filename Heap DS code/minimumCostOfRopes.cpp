#include<bits/stdc++.h>
using namespace std;
long long minCost(long long a[], long long n)
{
    // Your code here
    priority_queue<long long,vector<long long>,greater<long long>>pq(a,a+n);
    long long cost=0;
    while(pq.size()>=2)
    {
        long long firstRop=pq.top();
        pq.pop();
        long long secondRop=pq.top();
        pq.pop();
        cost+=firstRop+secondRop;
        pq.push(firstRop+secondRop);
    }
    return cost;
}

int main()
{
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++)cin>>a[i];

    long long ans=minCost(a,n);

    cout<<ans<<endl;
    return 0;
}

