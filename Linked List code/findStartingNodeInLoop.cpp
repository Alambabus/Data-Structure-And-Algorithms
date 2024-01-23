
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
        cout<<"Linked List: ";
        while(temp)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    //connect next of last node to first node
    Node *makingLoop(Node *head)
    {
        Node *temp=head;
        while(temp->next)temp=temp->next;
        temp->next=head;
        return head;
    }

    //finding first node in loop of Linked List
    int findFirstNode(Node* head)
    {
        if(!head)return -1;
        Node *slow=head,*fast=head;
        int flag=false;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                flag=true;
            break;
            }
        }
        if(flag==false)return -1;
        fast=head;
        if(slow==head)return head->data;
        while(fast->next != slow->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return fast->next->data;
    }

int main()
{
    //creating head node of linked List
    Node *head=NULL;

    int a[]={10,20,30,40,50};
    int n=sizeof(a)/sizeof(a[0]);

    //int a[]={10,20,30,40,50,60};
    //int n=sizeof(a)/sizeof(a[0]);

    //calling create function
    head=createLinkedList(a,n);

    //calling printLinkedList function
    printLinkedList(head);

    //calling making loop function
    head=makingLoop(head);

    //finding starting node point in loop
    int ans=findFirstNode(head);
     cout<<ans;
    return 0;
}
