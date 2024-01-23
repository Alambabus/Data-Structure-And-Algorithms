#include<iostream>
using namespace std;
class Node
{
    int data;
    Node *next;
public:
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }


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

    //delete nth node from end of Linked List
    Node * deleteNthNodeFromLinkedList(Node *head,int n)
    {
        Node *temp=head;
        int listSize=0;
        while(temp)
        {
            listSize++;
            temp=temp->next;
        }
        n=listSize-n;
        if(n==0)return head->next;
        temp=head;
        while(--n)
            temp=temp->next;
        temp->next=temp->next->next;
        return head;
    }
};


int main()
{
    //creating head node of linked List
    Node *head=NULL;

    int a[]={10,20,30,40,50};
    int n=sizeof(a)/sizeof(a[0]);

    //int a[]={10,20,30,40,50,60};
    //int n=sizeof(a)/sizeof(a[0]);

    //calling create function
    head=head->createLinkedList(a,n);

    //calling printLinkedList function
    head->printLinkedList(head);


    //delete nth node from end of Linked List
    //T.C.=O(n)
    //S.C.=O(1)
    head=head->deleteNthNodeFromLinkedList(head,5);

    //calling printLinkedList function
    head->printLinkedList(head);
    return 0;
}


