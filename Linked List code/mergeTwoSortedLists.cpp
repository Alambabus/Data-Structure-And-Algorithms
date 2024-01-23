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

Node* mergeTwoLists(Node* a, Node* b)
{
          Node *tail=NULL,*head=NULL;
          if(!a)return b;
          if(!b)return a;
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
          if(a)tail->next=a;
          if(b)tail->next=b;
        return head;
    }

int main()
{
    Node *l1=NULL,*l2=NULL;

    int a[]={1,2,4};
    int n1=sizeof(a)/sizeof(a[0]);

    l1=createLinkedList(l1,a,n1);
    printLinkedList(l1);

    int b[]={1,3,4};
    int n2=sizeof(b)/sizeof(b[0]);

    l2=createLinkedList(l2,b,n2);
    printLinkedList(l2);

    l1=mergeTwoLists(l1,l2);
    printLinkedList(l1);

    return 0;
}
