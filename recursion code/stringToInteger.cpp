#include<iostream>
using namespace std;
int convertStringToInt(string s,int i)
{
    //base case
    if(i<0)return 0;
    if(s[i]=='-')return 0;
    //recursive case
    return convertStringToInt(s,i-1)*10+(s[i]-'0');
}
int main()
{
    //string s="12345";
    string s="-12345";
    bool isNegative=false;
    if(s[0]=='-')isNegative=true;

    int ans=isNegative?-convertStringToInt(s,s.size()-1):convertStringToInt(s,s.size()-1);
    cout<<ans<<endl;
    return 0;
}
