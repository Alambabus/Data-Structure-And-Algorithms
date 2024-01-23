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
Node* reverseLinkedList(Node *head)
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
Node* reverseBetween(Node* head, int left, int right)
{
        Node *newHead=new Node(-1);
        newHead->next=head;
        head=newHead;
        int count=0;
        Node *lHead=NULL,*a=NULL,*b=NULL,*rHead=NULL,*temp=head;
        while(temp && count<=right)
        {
            if(left-1==count)lHead=temp;
            if(left==count)a=temp;
            if(right==count)b=temp;
            count++;
            temp=temp->next;
        }
        rHead=b->next;
        b->next=NULL;
        if(lHead)
        lHead->next=reverseLinkedList(a);
        a->next=rHead;
        return head->next;
}
int main()
{
    Node *head=NULL;

    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);

    head=createLinkedList(head,a,n);

    printLinkedList(head);

    int left=2,right=4;
    head=reverseBetween(head,left,right);

    printLinkedList(head);
    return 0;
}
