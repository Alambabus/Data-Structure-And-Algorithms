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

int maxDepth(TreeNode* root)
{
    //base case
    if(!root)return 0;
    //recursive case
    return max(maxDepth(root->left),maxDepth(root->right))+1;
}



int main()
{

    TreeNode *root=NULL;

    root=createBinaryTreePreorder();

    int maxDpth=maxDepth(root);

    cout<<maxDpth<<endl;

    return 0;
}

