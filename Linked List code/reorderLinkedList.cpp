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
    if(!temp)
    {
        cout<<"Linked List is Empty"<<endl;
        return ;
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
    Node *temp=head;
    if(!temp)return newNode;
    while(temp->next)
        temp=temp->next;
    temp->next=newNode;
    return head;
}

Node *createLinkedList(Node *head,int a[],int n)
{
    for(int i=0;i<n;i++)
        head=pushNodeInLinkedList(head,a[i]);
    return head;
}

Node*findMid(Node *head)
{
    Node *slow=head,*fast=head->next;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node *reverse(Node *head)
{
       Node *prev=NULL,*curr=head,*next=NULL;
       while(curr)
       {
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
       }
       return prev;
}
Node *reorderedList(Node *a,Node *b)
   {
       Node *dummyNode=new Node(-1);
       Node *temp=dummyNode;
       while(a && b)
       {
            temp->next=a;
            temp=a;
            a=a->next;
            temp->next=b;
            temp=b;
            b=b->next;
       }
       if(a)
       {
           temp->next=a;

       }
       if(b)
       {
           temp->next=b;
       }
       return dummyNode->next;
}
void reorderList(Node* head)
{
        Node * mid=findMid(head);
        Node *a=head,*b=mid->next;
        mid->next=NULL;
        b=reverse(b);
        head=reorderedList(a,b);
}

int main()
{
    Node *head=NULL;

    int a[]={1,2,3,4};
    int n=sizeof(a)/sizeof(a[0]);

    head=createLinkedList(head,a,n);

    printLinkedList(head);

    reorderList(head);

    printLinkedList(head);
    return 0;
}
