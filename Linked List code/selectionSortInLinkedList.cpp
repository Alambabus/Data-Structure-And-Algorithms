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
Node* sortList(Node* head)
    {
        Node *temp=head;
        while(temp)
        {
            int sValue=temp->data;
            Node *a=temp->next,*smallP=temp;
            while(a)
            {
                if(a->data<sValue)
                {
                    sValue=a->data;
                    smallP=a;
                }
                a=a->next;
            }
            swap(temp->data,smallP->data);
            temp=temp->next;
        }
        return head;
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

