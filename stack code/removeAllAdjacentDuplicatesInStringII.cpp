
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string naiveSolutionOfRemoveDuplicatesUsing(string s, int k)
{
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            char x=s[i];
            if(!ans.empty() && x==ans.back())
            {
                int k1=k;
                    bool flag=false;
                    int j=ans.size()-1;
                    for(int K=0;K<k-1;K++)
                    {
                        if(j>=0 && ans[j--] == x )
                        {
                            flag=true;
                        }
                        else {
                            flag=false;
                            break;
                        }
                    }
                    if(flag == true)
                    {
                        while(--k1)ans.pop_back();
                        continue;
                    }
            }
            ans.push_back(x);
        }
        return ans;
}
string efficientSolutionOfremoveDuplicates(string s, int k)
{
        int n=s.size();
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty() || st.top().first!=s[i])
            st.push({s[i],1});
            else{
                auto x=st.top();
                st.pop();
                st.push({s[i],x.second+1});
            }
            if(st.top().second==k)st.pop();
        }
        string ans="";
        while(!st.empty())
        {
            auto x=st.top();
            st.pop();
            int i=x.second;
            char c=x.first;
            while(i--)ans+=c;
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
int main()
{

    //string st="deeedbbcccbdaa";
    //int k=3;

    string st="abcd";
    int k=2;

    string ans=naiveSolutionOfRemoveDuplicatesUsing(st,k);
    cout<<ans<<endl;

    string ans1=efficientSolutionOfremoveDuplicates(st,k);
    cout<<ans1<<endl;

    return 0;
}
