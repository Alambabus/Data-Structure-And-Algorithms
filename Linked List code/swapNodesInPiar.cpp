#include<iostream>
#include<algorithm>
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

Node* swapPairs(Node* head)
{
        if(!head || !head->next)return head;
        Node *curr=head;
        while(curr && curr->next)
        {
            swap(curr->data,curr->next->data);
            curr=curr->next->next;
        }
        return head;
}

int main()
{
    Node *head=NULL;

    int a[]={1,2,3,4};
    int n=sizeof(a)/sizeof(a[0]);

    head=createLinkedList(head,a,n);

    printLinkedList(head);

    head=swapPairs(head);

    printLinkedList(head);

    return 0;
}

