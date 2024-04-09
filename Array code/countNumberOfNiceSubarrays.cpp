#include<bits/stdc++.h>
using namespace std;
int numberOfSubarrays(vector<int>& a, int k)
{
    int n=a.size();
    int count=0,ans=0;
    int i=0,j=0;
    while(j<n)
    {
        if(a[j]%2==1)count++;
        if(count==k)
        {
            ans++;
            while(i<j)
            {
                if(a[j]%2==1){
                    count--;
                    i++;
                    break;
                }
                i++;
            }
        }
        j++;
    }
    return ans;
}
int main()
{
    vector<int>a={1,1,2,1,1};
    int k=3;
    int ans=numberOfSubarrays(a,k);
    cout<<ans<<endl;
    return 0;
}
