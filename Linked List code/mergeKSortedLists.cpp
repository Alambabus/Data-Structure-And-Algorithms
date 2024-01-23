#include<iostream>
#include<vector>
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
Node *createLinkedList(vector<int>a)
{
    Node *head=NULL;
    for(auto x:a)
        head=pushNodeInLinkedList(head,x);
    return head;
}
Node* mergeTwoList(Node* a,Node* b)
{
    if(!a)return b;
    if(!b)return a;
    Node *head=NULL,*tail=NULL;
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
    if(a)
        tail->next=a;
    if(b)
        tail->next=b;
    return head;
}
Node* mergeKLists(vector<Node*>& lists)
{
        if(lists.size()==0)return NULL;
        Node *a=NULL;
        for(auto list:lists)
            a=mergeTwoList(a,list);
        return a;

}
int main()
{
    vector<vector<int>>a={{1,4,5},{1,3,4},{2,6}};
    vector<Node *>lists;
    for(auto x:a)
        lists.push_back(createLinkedList(x));
    Node *head=mergeKLists(lists);
    if(!head)cout<<"List is Empty"<<endl;
    else
    {
        Node *temp=head;
        while(temp)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
    }
    return 0;
}

