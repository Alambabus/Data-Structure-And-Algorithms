#include<bits/stdc++.h>
using namespace std;
void insertToMinHeap(vector<int> &a,int i)
{

    while(i>0 && a[(i-1)/2]>a[i])
    {
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2;
    }
}
void deleteToMinHeap(vector<int> &a,int n)
{
    swap(a[0],a[n]);
    int i=0,j=2*i+1;
    while(j<n)
    {
        int leftChild=a[j];
        int rightChild=INT_MAX;
        if(j+1<n)rightChild=a[j+1];
        if(rightChild<leftChild)j=j+1;
        if(a[j]<
           a[i])
        {
            swap(a[j],a[i]);
            i=j;
            j=2*i+1;
        }
        else break;
    }
}
void heapSort(vector<int> &a)
{
    int n=a.size();
    for(int i=0;i<n;i++)
        insertToMinHeap(a,i);

    for(auto x:a)cout<<x<<" ";
    cout<<endl;

    for(int i=n-1;i>=0;i--)
        deleteToMinHeap(a,i);

    for(auto x:a)cout<<x<<" ";
    cout<<endl;

}
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    heapSort(a);
    return 0;
}
