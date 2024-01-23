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
Node *oddEvenLinkedList(Node *head)
{
    Node *es=NULL,*ee=NULL,*os=NULL,*oe=NULL;
    int node=1;
    Node *temp=head;
    while(temp)
    {
        if(node%2)
        {
            if(os==NULL)
            {
                os=temp;
                oe=temp;
            }
             else
             {
                 oe->next=temp;
            oe=temp;
             }
        }
        else
        {
            if(es==NULL)
            {
                es=temp;
                ee=temp;
            }
            else{
                ee->next=temp;
            ee=temp;
            }
        }
        temp=temp->next;
        node++;
    }
    if(es)
    {
        oe->next=es;
        ee->next=NULL;
    }
    if(!os)return es;
    return os;
}
int main()
{
    Node *head=NULL;

    int a[]={2,1,3,5,6,4,7};
    int n=sizeof(a)/sizeof(a[0]);

    head=createLinkedList(head,a,n);

    printLinkedList(head);

    head=oddEvenLinkedList(head);

    printLinkedList(head);
    return 0;
}
