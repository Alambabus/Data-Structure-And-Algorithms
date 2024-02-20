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

TreeNode* invertTree(TreeNode* root)
{
    if(!root)return NULL;
    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
void printTree(TreeNode *root)
{
    if(root)
    {
        printTree(root->left);
        cout<<root->val<<" ";
        printTree(root->right);
    }

}
int main()
{
    TreeNode *root=createBinaryTreePreorder();

    printTree(root);
    cout<<endl;

    root=invertTree(root);

    printTree(root);
    cout<<endl;

    return 0;
}
