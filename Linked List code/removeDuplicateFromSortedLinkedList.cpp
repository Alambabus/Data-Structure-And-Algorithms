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

Node *removeDuplicates(Node *head)
{
 // your code goes here
 if(!head->next)return head;
 Node *a=head,*b=head->next;
 while(b)
 {
     if(a->data == b->data)a->next=b->next;
     else  a=b;
     b=b->next;

 }
 return head;
}


int main()
{
    Node *head=NULL;

    int a[]={1,2,2,2,3,3,4,5,5,6,7,8,9,10};
    int n=sizeof(a)/sizeof(a[0]);

    head=createLinkedList(head,a,n);
    printLinkedList(head);

    head=removeDuplicates(head);
    printLinkedList(head);

    return 0;
}
