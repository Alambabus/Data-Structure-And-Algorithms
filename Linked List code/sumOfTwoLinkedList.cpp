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
Node* addTwoNumbers(Node* l1, Node* l2)
{

      Node *dummy=new Node(-1);
      Node *temp=dummy;
      int carry=0;
      while(l1!=NULL || l2!=NULL || carry)
      {
          int sum=0;
          if(l1!=NULL)
          {
               sum+=l1->data;
               l1=l1->next;
          }
          if(l2!=NULL)
          {
               sum+=l2->data;
               l2=l2->next;
          }
          sum+=carry;
          carry=sum/10;
          Node *node=new Node(sum%10);
          temp->next=node;
          temp=temp->next;
      }
      return dummy->next;

}
int main()
{
    Node *l1=NULL,*l2=NULL;

    int a[]={2,4,3};
    int b[]={5,6,4};

    int n=sizeof(a)/sizeof(a[0]);
    l1=createLinkedList(l1,a,n);

    n=sizeof(b)/sizeof(b[0]);
    l2=createLinkedList(l2,b,n);

    printLinkedList(l1);
    printLinkedList(l2);

    l1=addTwoNumbers(l1,l2);

    printLinkedList(l1);

    return 0;
}
