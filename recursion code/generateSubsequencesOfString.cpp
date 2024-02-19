#include<iostream>
using namespace std;
void generateSubsequencesOfStringHelper(string &s,int i,string subSeq,int n)
{
    //base case
    if(i==n)
    {
        cout<<subSeq<<endl;
        return;
    }
    //recursive case
    generateSubsequencesOfStringHelper(s,i+1,subSeq+s[i],n);
    generateSubsequencesOfStringHelper(s,i+1,subSeq,n);
}
void generateSubsequencesOfString(string &s)
{
    string subSeq="";
    generateSubsequencesOfStringHelper(s,0,subSeq,s.size());
}
void generateSubsequencesOfStringByBactrakingHelper(string &s,int i,string &subSeq,int n)
{

    //base case
    if(i==n)
    {
        cout<<subSeq<<endl;
        return;
    }
    //recursive case
    subSeq+=s[i];
    generateSubsequencesOfStringByBactrakingHelper(s,i+1,subSeq,n);
    subSeq.pop_back();
    generateSubsequencesOfStringByBactrakingHelper(s,i+1,subSeq,n);
}
void generateSubsequencesOfStringByBactraking(string &s)
{
    string subSeq="";
    generateSubsequencesOfStringByBactrakingHelper(s,0,subSeq,s.size());
}
int main()
{
    string s="abc";

    //generateSubsequencesOfString(s);
    generateSubsequencesOfStringByBactraking(s);
    return 0;
}
