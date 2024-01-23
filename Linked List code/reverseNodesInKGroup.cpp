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

    //insertion of LinkedList as Last
    Node *insertNode(Node *head,int data)
    {
        Node *newNode=new Node(data);
        if(!head)return newNode;
        Node *temp=head;
        while(temp->next)
            temp=temp->next;
        temp->next=newNode;
        return head;
    }

    //creating  Linked list
    Node * createLinkedList(int a[],int n)
    {
        Node *head=NULL;
        for(int i=0;i<n;i++)
        {
            head=insertNode(head,a[i]);
        }
        return head;
    }

    //Traversal of Linked List
    void printLinkedList(Node *head)
    {
        Node *temp=head;
        if(!head)
        {
            cout<<"Linked List is Empty"<<endl;
            return;
        }
        cout<<"Linked List: "<<endl;
        while(temp)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
     }
Node *reverseLinkedList(Node *head)
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
Node* reverseKGroup(Node* head, int k)
{
        //base case
        if(!head)return NULL;
        //recursive case
        int cnt=1;
        Node *temp=head;
        while(temp && k>cnt)
        {
            cnt++;
            temp=temp->next;
        }
        // if(cnt<k)return head;
        if(cnt==k && temp)
        {
            Node *next=temp->next;
            temp->next=NULL;
            Node *newHead=reverseLinkedList(head);
            head->next=reverseKGroup(next,k);
            return newHead;
        }
        return head;
    }
int main()
{
    Node *head=NULL;

    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);

    head=createLinkedList(a,n);

    printLinkedList(head);

    head=reverseKGroup(head,2);
    printLinkedList(head);

    return 0;
}
