#include<iostream>
#include<vector>
using namespace std;
class Stack
{
    public:
    vector<int>a;

    //inserting an element in  top of stack
    void push(int data)
    {
        a.push_back(data);
    }

    //deleting top element of stack
    void pop()
    {
        if(a.size()==0)
        {
            cout<<"Stack is Underflow"<<endl;
            return ;
        }
        a.pop_back();
    }
    int size()
    {
        return a.size();
    }

    //finding the top of stack
    int top()
    {
        if(a.size()==0)
        {
            cout<<"Stack is Underflow"<<endl;
            return -1;
        }
        return a[a.size()-1];
    }

    //ckecking stack is empty or not
    bool isEmpty()
    {
        if(a.size()==0)return true;
        return false;
    }

    //printing stack
    void printStack()
    {
        int n=a.size();
        for(int i=n-1;i>=0;i--)
            cout<<a[i]<<endl;
    }
};

void createStack(Stack &s,int arr[],int n)
{
    for(int i=0;i<n;i++)
        s.push(arr[i]);
}

int main()
{
    Stack s;

    //s.push(10);

    int arr[]={60,50,40,30,20,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    createStack(s,arr,n);

    s.printStack();

    s.pop();
    cout<<"After Poping one Element from top of stack"<<endl;
    s.printStack();

    int sz=s.size();
    cout<<"Size of Stack: "<<sz<<endl;

    int t=s.top();
    if(t != -1)cout<<"Top of stack: "<<t<<endl;

    bool ans=s.isEmpty();
    if(ans)cout<<"True"<<endl;
    else cout<<"False"<<endl;

    return 0;
}
