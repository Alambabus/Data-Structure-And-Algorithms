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

TreeNode *helper(int s,int e,vector<int> &a)
{
    //base case
    if(s>e)return NULL;
    //recursive case
    int mid=(s+e)/2;
    TreeNode *root=new TreeNode(a[mid]);
    root->left=helper(s,mid-1,a);
    root->right=helper(mid+1,e,a);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& a)
{
    int n=a.size();
    TreeNode *root=helper(0,n-1,a);
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

int main()
{
    vector<int>a={1,2,3,4,5,6,7,8,9,10};

    TreeNode *root=sortedArrayToBST(a);

    inorderTraversalOfBST(root);



    return 0;
}
