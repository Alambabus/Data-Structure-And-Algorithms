#include<iostream>
using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    int val;
    TreeNode *right;
    TreeNode(int val)
    {
        this->left=NULL;
        this->val=val;
        this->right=NULL;
    }
};
TreeNode *createBinaryTreePreorder()
{
    int data;
    cin>>data;
    if(data==-1)return NULL;
    TreeNode *root=new TreeNode(data);
    root->left=createBinaryTreePreorder();
    root->right=createBinaryTreePreorder();
    return root;
}

void flatten(TreeNode* root)
{
    //base case
    if(!root)return ;
    TreeNode *t=root;
    if(t->left)
    {
        TreeNode *b=t->left;
        while(b->right)b=b->right;
        b->right=t->right;
        t->right=t->left;
        t->left=NULL;

    }
        flatten(t->right);
}
void printTree(TreeNode *root)
{
    while(root)
    {
        cout<<root->val<<" ";
        root=root->right;
    }
}

int main()
{
    TreeNode *root=createBinaryTreePreorder();
    flatten(root);
    printTree(root);

    return 0;
}
