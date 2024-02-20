#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    int data;
    TreeNode *right;
    TreeNode(int data)
    {
        this->left=NULL;
        this->data=data;
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

int countNodes(TreeNode* root)
{
    //base case
    if(!root)return 0;
    //revursive case
    return countNodes(root->left)+countNodes(root->right)+1;
}



int main()
{

    TreeNode *root=NULL;

    root=createBinaryTreePreorder();

    int countNode=countNodes(root);

    cout<<countNode<<endl;

    return 0;
}
