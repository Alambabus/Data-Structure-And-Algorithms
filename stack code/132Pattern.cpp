#include<iostream>
#include<stack>
#include<vector>
using namespace std;
bool find132pattern(vector<int>& nums)
{
    int numK=INT_MIN;
    stack<int>s;
    int n=nums.size();
    for(int i=n-1;i>=0;i--)
    {
        if(nums[i]<numK)return true;
        while(!s.empty() && s.top()<nums[i])
        {
            numK=s.top();
            s.pop();
        }
        s.push(nums[i]);
    }
    return false;
}
int main()
{
   vector<int>nums={3,1,4,2};

    bool ans=find132pattern(nums);
    if(ans)cout<<"True"<<endl;
    else cout<<"False"<<endl;

    return 0;
}
