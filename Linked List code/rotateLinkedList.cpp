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

Node *rotateLinkedList1(Node *head,int k)
{
    if(!head || !head->next)return head;

        int n=0;
        Node *temp=head;
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==0)return head;
        temp=head;
        k=n-k;
        while(--k && temp)
        {
            temp=temp->next;
        }
        Node *next=temp->next;
        temp->next=NULL;
        temp=next;
        while(temp->next)temp=temp->next;
        temp->next=head;
        head=next;
        return head;
}

Node *rotateLinkedList2(Node *head,int k)
{
    if(head==NULL)
        return NULL;
        Node *slow=head,*fast=head,*t=head;
        int n=0;
        while(t)
        {
            n++;
            t=t->next;
        }
        k%=n;
        if(k==0)
        return head;
        while(fast && k--)fast=fast->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        Node *p=slow->next;
        slow->next=NULL;
        if(fast)
        fast->next=head;
        return p;
}
int main()
{
    Node *head=NULL;

    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);

    head=createLinkedList(head,a,n);

    printLinkedList(head);

    //head=rotateLinkedList1(head,2);

    //printLinkedList(head);
    cout<<endl;

    head=rotateLinkedList2(head,2);

    printLinkedList(head);

    return 0;
}
