#include<iostream>
#include<vector>
using namespace std;
void  generateBinaryStringsHelper(int num,vector<string> &ans,string st)
{
    //base case
    if(num<=0)
    {
        ans.push_back(st);
        return;
    }
    //recursive case
    st+='0';
    generateBinaryStringsHelper(num-1,ans,st);
    st.pop_back();
    if(st[st.size()-1]=='1')return ;
    st+='1';
    generateBinaryStringsHelper(num-1,ans,st);
}
vector<string> generateBinaryStrings(int num)
{
    vector<string>ans;
    string st="";
    generateBinaryStringsHelper(num,ans,st);
    return ans;
}
int main()
{
    int n=3;//1,2,3

    vector<string>ans=generateBinaryStrings(n);
    for(auto x:ans)cout<<x<<endl;

    return 0;
}
