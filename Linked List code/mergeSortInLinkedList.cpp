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
Node *pushNodeInLinkedList(Node *head,int data)
{
    Node *temp=head;
    Node *newNode=new Node(data);
    if(!head)return newNode;
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
Node* findMidOfLinkedList(Node *head)
{
        Node *slow=head,*fast=head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
}
Node* mergeTwoList(Node* a,Node* b)
{
        if(!a)return b;
        if(!b)return a;
        Node *head=NULL,*tail=NULL;
        if(a->data<b->data)
        {
            head=a;
            tail=a;
            a=a->next;
        }
        else
        {
           head=b;
           tail=b;
           b=b->next;
         }
        while(a && b)
       {
         if(a->data<b->data)
         {
            tail->next=a;
            tail=a;
            a=a->next;
         }
        else
        {
            tail->next=b;
            tail=b;
            b=b->next;
        }
    }
    if(a)
        tail->next=a;
    if(b)
        tail->next=b;
    return head;
}
Node* sortList(Node* head)
{
        //base case
        if(!head || !head->next)
        return head;
        //recursive case
        Node *mid=findMidOfLinkedList(head);
        Node *b=mid->next;
        mid->next=NULL;
        Node *left=sortList(head);
        Node *right=sortList(b);
        return mergeTwoList(left,right);
}
void printList(Node *head)
{
    Node *temp=head;
    if(!head)
    {
        cout<<"Linked List is Empty"<<endl;
        return ;
    }
    while(temp)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
int main()
{
    Node *head=NULL;

    int a[]={4,2,1,3};
    int n=sizeof(a)/sizeof(a[0]);

    head=createLinkedList(head,a,n);

    head=sortList(head);

    printList(head);

    return 0;
}


