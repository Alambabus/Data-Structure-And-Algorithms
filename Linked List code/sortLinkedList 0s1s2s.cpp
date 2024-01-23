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

Node* segregate(Node *head)
{

        // Add code here
        int zero=0,one=0,two=0;
        Node *temp=head;
        while(temp)
        {
            if(temp->data==0)zero++;
            else if(temp->data==1)one++;
            else two++;
            temp=temp->next;
        }
        Node *dummyNode=new Node(-1);
        temp=dummyNode;
        while(zero && zero--)
        {
            Node *newNode=new Node(0);
            temp->next=newNode;
            temp=newNode;
        }
        while(one && one--)
        {
            Node *newNode=new Node(1);
            temp->next=newNode;
            temp=newNode;
        }
        while(two && two--)
        {
            Node *newNode=new Node(2);
            temp->next=newNode;
            temp=newNode;
        }
        return dummyNode->next;

}
int main()
{
    Node *head=NULL;

    int a[]={1,2,2,1,2,0,2,2};
    int n=sizeof(a)/sizeof(a[0]);

    head=createLinkedList(head,a,n);

    printLinkedList(head);

    head=segregate(head);

    printLinkedList(head);

    return 0;
}
