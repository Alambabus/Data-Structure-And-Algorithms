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

    //reversing Linked List
    Node * reverseLinkedListInIterativeWay(Node *head)
    {
        if(!head || !head->next)return head;
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
    void helperFunction(Node *&curr,Node *&prev)
    {
        //base case
        if(!curr)return;

        //recursive case
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        helperFunction(next,prev);
    }
    Node *reverseLinkedListInRecersiveWay(Node *head)
    {
        Node *prev=NULL;
        helperFunction(head,prev);
        return prev;
    }


int main()
{
    //creating head node of linked List
    Node *head=NULL;

    //int a[]={10,20,30,40,50};
    //int n=sizeof(a)/sizeof(a[0]);

    int a[]={10,20,30,40,50,60};
    int n=sizeof(a)/sizeof(a[0]);

    //calling create function
    head=createLinkedList(a,n);

    //calling printLinkedList function
    printLinkedList(head);

    //calling reverse function
    //head=reverseLinkedListInIterativeWay(head);

    //calling printLinkedList function
    //printLinkedList(head);

    //caling reverse function
    head=reverseLinkedListInRecersiveWay(head);

    //calling printLinkedList function
    printLinkedList(head);
    return 0;
}
