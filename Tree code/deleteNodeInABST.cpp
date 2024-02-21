#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    int val;
    TreeNode *right;
    TreeNode(int data)
    {
        this->left=NULL;
        this->val=data;
        this->right=NULL;
    }
};

TreeNode *insertNodeToBST(TreeNode *root,int val)
{
    //base case
    if(!root)return new TreeNode(val);
    //recursive case
    if(root->val<val)root->right=insertNodeToBST(root->right,val);
    else root->left=insertNodeToBST(root->left,val);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& pre)
{
    TreeNode *root=NULL;
    int n=pre.size();
    for(int i=0;i<n;i++)root=insertNodeToBST(root,pre[i]);

    return root;
}
void inorderTraversalOfBST(TreeNode *root)
{
    if(root)
    {
        inorderTraversalOfBST(root->left);
        cout<<root->val<<" ";
        inorderTraversalOfBST(root->right);
    }
}
TreeNode *findLastRight(TreeNode *root)
{
    //base case
    if(!root->right)return root;
    //recursive case
    return findLastRight(root->right);
}
TreeNode *helper(TreeNode *root)
{
    if(!root->right)return root->left;
    if(!root->left)return root->right;
    TreeNode *rightChild=root->right;
    TreeNode *leftChild=root->left;
    TreeNode *lastRight=findLastRight(leftChild);
    lastRight->right=rightChild;
    return root->left;
}
TreeNode* deleteNode(TreeNode* root, int key)
{
    if(!root)return NULL;
    if(root->val==key)return helper(root);
    TreeNode *dummyNode=root;
    while(root)
    {
        if(root->val>key)
        {
            if(root->left && root->left->val==key)root->left=helper(root->left);
            else root=root->left;
        }
        else
        {
            if(root->right && root->right->val==key)root->right=helper(root->right);
            else root=root->right;
        }
    }
    return dummyNode;
}
int main()
{
    vector<int>pre={8,5,1,7,10,12};

    TreeNode *root=bstFromPreorder(pre);

    inorderTraversalOfBST(root);

    deleteNode(root,7);

    cout<<endl;

    inorderTraversalOfBST(root);

    return 0;
}
