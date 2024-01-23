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

Node *reverseLinkedList(Node *head)
{
    Node *prev=NULL,*next=NULL,*curr=head;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
bool isPalindrome(Node* head)
{
    Node *a=head,*b=NULL,*slow=head,*fast=head->next;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    b=slow->next;
    slow->next=NULL;
    b=reverseLinkedList(b);
    while(a && b)
    {
        if(a->data != b->data)return false;
        a=a->next;
        b=b->next;
    }
    return true;
}
int main()
{
    Node *head=NULL;

    int a[]={1,2,2,1};

    int n=sizeof(a)/sizeof(a[0]);

    head=createLinkedList(head,a,n);

    printLinkedList(head);

    bool ans=isPalindrome(head);
    if(ans)cout<<"True"<<endl;
    else cout<<"False"<<endl;

    return 0;
}

