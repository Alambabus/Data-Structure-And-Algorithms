#include<iostream>
using namespace std;
class Node
{
public:
    Node *left;
    int data;
    Node *right;
    Node(int data)
    {
        this->left=NULL;
        this->data=data;
        this->right=NULL;
    }
};


Node *createBinaryTreePreorder()
{
    int data;
    cin>>data;
    if(data==-1)return NULL;
    Node *root=new Node(data);
    root->left=createBinaryTreePreorder();
    root->right=createBinaryTreePreorder();
    return root;
}


void preOrderTraversalRecursive(Node *root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preOrderTraversalRecursive(root->left);
        preOrderTraversalRecursive(root->right);

    }

}

void inOrderTraversalRecursive(Node *root)
{
    if(root)
    {
        inOrderTraversalRecursive(root->left);
        cout<<root->data<<" ";
        inOrderTraversalRecursive(root->right);
    }
}

void postOrderTraversalRecursive(Node *root)
{
    if(root)
    {
        postOrderTraversalRecursive(root->left);
        postOrderTraversalRecursive(root->right);
        cout<<root->data<<" ";
    }
}
int main()
{
    Node *root=NULL;

    root=createBinaryTreePreorder();

    preOrderTraversalRecursive(root);
    cout<<endl;

    inOrderTraversalRecursive(root);
    cout<<endl;

    postOrderTraversalRecursive(root);
    cout<<endl;

    return 0;
}
