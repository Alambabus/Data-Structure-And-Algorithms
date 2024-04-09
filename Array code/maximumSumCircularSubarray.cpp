#include<bits/stdc++.h>
using namespace std;
int minSubArraySum(vector<int> &a)
{
    int n=a.size();
    int currSum=0;
    int minSum=INT_MAX;
    for(int i=0;i<n;i++)
    {
        currSum+=a[i];
        minSum=min(minSum,currSum);
        if(currSum>0)currSum=0;
    }
    return minSum;
}
int maxSubArraySum(vector<int> &a)
{
    int n=a.size();
    int currSum=0;
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        currSum+=a[i];
        maxSum=max(maxSum,currSum);
        if(currSum<0)currSum=0;
    }
    return maxSum;
}
int maxSubarraySumCircular(vector<int>& a)
{
    int n=a.size();
    int op1=maxSubArraySum(a);
    int min=minSubArraySum(a);
    int totalSum=0;
    for(int i=0;i<n;i++)totalSum+=a[i];
    int op2=totalSum-min;
    if(op2==0)return op1;
    return max(op1,op2);
}
int main()
{
    vector<int>a={1,-2,3,-2};
    int ans=maxSubarraySumCircular(a);
    cout<<ans<<endl;
    return 0;
}
