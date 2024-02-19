#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>>minHeap;
priority_queue<int>maxHeap;


//Function to balance heaps.
void balanceHeaps()
{
    int maxSz=maxHeap.size();
    int minSz=minHeap.size();
    if(abs(maxSz-minSz)<=1)return ;
    if(maxSz-minSz>1)
    {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else
    {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }

}

//Function to return Median.
double getMedian()
{

    int maxSz=maxHeap.size();
    int minSz=minHeap.size();
    if((maxSz+minSz)%2==0)return (maxHeap.top()+minHeap.top())/(double)2;
    if(maxSz>minSz)return maxHeap.top();
    else return minHeap.top();
}

void insertHeap(int &x)
{
    int maxSz=maxHeap.size();
    int minSz=minHeap.size();
    if(maxSz==0 && minSz==0)
    {
        maxHeap.push(x);
        return;
    }

    double currMed=getMedian();
    if(x<=currMed)
    {
      maxHeap.push(x);

    }
    else minHeap.push(x);
    balanceHeaps();
}


int main()
{
    int n;
    cin>>n;
    while(n)
    {
        int inp;
        cin>>inp;
        insertHeap(inp);
        cout<<floor(getMedian())<<" ";
        n--;
    }
    return 0;
}
