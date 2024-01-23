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
void printLinkedList(Node *head)
{

    Node *temp=head;
    if(!head)
    {
        cout<<"Linked List is Empty"<<endl;
        return;
    }
    cout<<"Linked List: ";
    while(temp)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
Node *pushNodeInLinkedList(Node *head,int data)
{
    Node *newNode=new Node(data);
    if(!head)return newNode;
    Node *temp=head;
    while(temp->next)temp=temp->next;
    temp->next=newNode;
    return head;
}
Node *createLinkedList(Node *head,int a[],int n)
{
    for(int i=0;i<n;i++)
        head=pushNodeInLinkedList(head,a[i]);
    return head;
}
//logice is write
Node *getIntersectionNode(Node *a, Node *b)
{
        int n1=0,n2=0;
        Node *temp=a;
        while(temp)
        {
            n1++;
            temp=temp->next;
        }
        temp=b;
        while(temp)
        {
            n2++;
            temp=temp->next;
        }
        int n=abs(n1-n2);
        if(n1>n2)temp=a;
        else temp=b;
        while(n--)temp=temp->next;
        if(n1>n2)a=temp;
        else b=temp;
        while(a && b)
        {
            if(a->data == b->data)return a;
            a=a->next;
            b=b->next;
        }
        return NULL;
}

int main()
{
    Node *l1=NULL,*l2=NULL;

    int a[]={4,1,8,4,5};
    int n1=sizeof(a)/sizeof(a[0]);

    l1=createLinkedList(l1,a,n1);
    printLinkedList(l1);

    int b[]={5,6,1,8,4,5};
    int n2=sizeof(b)/sizeof(b[0]);

    l2=createLinkedList(l2,b,n2);
    printLinkedList(l2);

    Node *ans=getIntersectionNode(l1,l2);
    if(ans)cout<<ans->data<<endl;
    else cout<<"Not Intersection Present in Two Linked List"<<endl;

    return 0;
}
