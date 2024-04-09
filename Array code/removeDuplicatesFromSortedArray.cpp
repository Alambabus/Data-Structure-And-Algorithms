#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums)
{
    int n=nums.size();
    int i=0,j=0;
    while(j<n)
    {
        if(nums[i]!=nums[j])swap(nums[++i],nums[j]);
        j++;
    }
    return i+1;
}
int main()
{
    vector<int>a={0,0,1,1,1,2,2,3,3,4};
    int n=removeDuplicates(a);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
    return 0;
}
