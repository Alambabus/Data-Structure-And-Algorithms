#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int celebrityIterative(vector<vector<int>>& M, int n)
{
    for(int i=0;i<n;i++)
    {
        int isCelebrity=true;
        for(int j=0;j<n;j++)
        {
            if(M[i][j]==1)
            {
                isCelebrity=false;
                break;
            }
        }
        if(isCelebrity)
        {
            for(int j=0;j<n;j++)
            {
                if(j==i)continue;
                if(M[j][i]==0)
                {
                    isCelebrity=false;
                }
            }
        }
        if(isCelebrity)return i;
    }
    return -1;
}
bool isCelebrity(int p,vector<vector<int> >& M)
{
        int n=M.size();
        for(int i=0;i<n;i++)
        if(M[p][i]==1)return false;
        for(int i=0;i<n;i++)
        {
            if(p==i)continue;
            if(M[i][p]==0)return false;
        }
        return true;
}
int celebrityRecursive(vector<vector<int> >& M, int n)
{
    stack<int>s;
    for(int i=0;i<n;i++)s.push(i);
    while(s.size()>1)
    {
        int firstPerson=s.top();
        s.pop();
        int secondPerson=s.top();
        s.pop();
        if(M[firstPerson][secondPerson]==1)s.push(secondPerson);
        else s.push(firstPerson);
    }
    int celebrityPerson=s.top();
    bool chk=isCelebrity(celebrityPerson,M);
    if(chk)return celebrityPerson;
    return -1;
}
int main()
{
    vector<vector<int>>m={{0,1,0},{0,0,0},{0,1,0}};
    int n=m.size();

    int ans=celebrityIterative(m,n);
    cout<<ans<<endl;

    int ans1=celebrityRecursive(m,n);
    cout<<ans1<<endl;

    return 0;
}
