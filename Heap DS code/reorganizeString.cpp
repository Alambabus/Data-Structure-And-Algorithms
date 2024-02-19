#include<bits/stdc++.h>
using namespace std;


string reorganizeString(string s)
{
    int n=s.size();
    map<char,int>m;
    for(int i=0;i<n;i++)m[s[i]]++;

    priority_queue<pair<int,char>>pq;//maxHeap
    for(auto x:m)pq.push({x.second,x.first});
    string ans="";
    while(pq.size()>1)
    {
        char firstChar=pq.top().second;
        int firstFre=pq.top().first;
        pq.pop();

        char secondChar=pq.top().second;
        int secondFre=pq.top().first;
        pq.pop();

        ans+=firstChar;
        firstFre--;
        ans+=secondChar;
        secondFre--;
        if(firstFre>0)pq.push({firstFre,firstChar});
        if(secondFre>0)pq.push({secondFre,secondChar});
    }
    if(pq.size()==0)return ans;
    if(pq.top().first>1)return "";
    return ans+pq.top().second;
}

int main()
{

    string s="aab";

    string ans=reorganizeString(s);

    cout<<ans<<endl;
    return 0;
}
