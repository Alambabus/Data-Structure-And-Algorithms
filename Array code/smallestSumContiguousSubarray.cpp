#include<bits/stdc++.h>
using namespace std;
int smallestSumSubarray(vector<int>& a)
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
int main()
{
    vector<int>nums={3,-4, 2,-3,-1, 7,-5};
    int ans=smallestSumSubarray(nums);
    cout<<ans<<endl;
    return 0;
}
