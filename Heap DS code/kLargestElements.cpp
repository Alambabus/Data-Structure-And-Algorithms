#include<bits/stdc++.h>
using namespace std;
vector<int> kLargest(int arr[], int n, int k) {
    // code here
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=0;i<k;i++)q.push(arr[i]);
    for(int i=k;i<n;i++)
    {
        if(q.top()<arr[i])
        {
            q.pop();
            q.push(arr[i]);
        }
    }
    vector<int>ans(q.size());
    for(int i=q.size()-1;i>=0;i--)
    {
        ans[i]=q.top();
        q.pop();
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int k=2;

    vector<int>ans=kLargest(a,n,k);

    for(auto x:ans)cout<<x<<" ";cout<<endl;
    return 0;
}
