#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int>& a)
{
    int n=a.size();
    int maxSum=INT_MIN;
    int currSum=0;
    for(int i=0;i<n;i++)
    {
        currSum+=a[i];
        maxSum=max(maxSum,currSum);
        if(currSum<0)currSum=0;
    }
    return maxSum;
}
int main()
{
    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};
    int ans=maxSubArray(nums);
    cout<<ans<<endl;
    return 0;
}
