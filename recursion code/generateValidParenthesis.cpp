#include<iostream>
#include<vector>
using namespace std;
void generateParenthesisHelper(int n,int ob,int cb,vector<string> &ans,string &st)
{
        //base case
        if(ob==n/2 && cb==n/2)
        {
            ans.push_back(st);
            return ;
        }
        //recursive case
        if(ob<n/2)
        {
            st+='(';
            generateParenthesisHelper(n,ob+1,cb,ans,st);
            st.pop_back();
        }
        if(cb<ob)
        {
            st+=')';
            generateParenthesisHelper(n,ob,cb+1,ans,st);
            st.pop_back();
        }
}
vector<string> generateParenthesis(int n)
{
    n=n*2;
    int ob=0,cb=0;
    vector<string>ans;
    string st="";
    generateParenthesisHelper(n,ob,cb,ans,st);
    return ans;
}
int main()
{
    int n=2;//1,2,3

    vector<string>ans=generateParenthesis(n);
    for(auto x:ans)cout<<x<<endl;

    return 0;
}
