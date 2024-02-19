#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

//inserting element in top of stack
Node *push(Node *top,int data)
{
    Node *newNode=new Node(data);
    newNode->next=top;
    return newNode;
}

//printing stack
void printStack(Node *top)
{
    if(!top)
    {
        cout<<"Stack is Empty"<<endl;
        return;
    }
    Node *t=top;
    while(t)
    {
        cout<<t->data<<endl;
        t=t->next;
    }
}


Node *createStack(Node *top,int a[],int n)
{
    for(int i=0;i<n;i++)
        top=push(top,a[i]);
    return top;
}

//deleting top element from stack
Node *pop(Node *top)
{

    if(!top)
    {
      cout<<"Stack is Empty.We can't perform deletion."<<endl;
      return NULL;
    }
    return top->next;
}

//top of stack
int topStack(Node *top)
{
    if(!top)return -1;
    return top->data;
}

//checking stack is empty or not
bool isEmpty(Node *top)
{
    if(!top)return true;
    return false;
}

//finding size of stack
int size(Node *top)
{
    if(!top)return 0;
    int cnt=0;
    Node *t=top;
    while(t)
    {
        cnt++;
        t=t->next;
    }
    return cnt;
}

int main()
{
    Node *top=NULL;

    //top=push(top,10);

    int a[]={60,50,40,30,20,10};
    int n=sizeof(a)/sizeof(a[0]);

    top=createStack(top,a,n);

    printStack(top);

    top=pop(top);
    cout<<"After Poping the stack: "<<endl;
    printStack(top);

    int t=topStack(top);
    if(t!=-1)cout<<"Top of Stack: "<<t<<endl;

    bool ans=isEmpty(top);
    if(ans)cout<<"True"<<endl;
    else cout<<"False"<<endl;

    int sz=size(top);
    cout<<"Size of Stack: "<<sz<<endl;
    return 0;
}
