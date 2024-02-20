#include<bits/stdc++.h>
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
int idx;
TreeNode *helper(int s,int e,vector<int>& in, vector<int>& post)
{
    //base case
    if(s>e)return NULL;
    //recursive case
    int k=-1;
    int val=post[idx--];
    for(int i=s;i<=e;i++)
    {
        if(val==in[i])
        {
            k=i;
            break;
        }
    }
    TreeNode *root=new TreeNode(in[k]);
    root->right=helper(k+1,e,in,post);
    root->left=helper(s,k-1,in,post);
    return root;
}
TreeNode* buildTree(vector<int>& post, vector<int>& in)
{
    int n=in.size();
    idx=n-1;
    TreeNode *root=helper(0,n-1,in,post);
    return root;
}
void inorderTraversalOfBT(TreeNode *root)
{
    if(root)
    {
        inorderTraversalOfBT(root->left);
        cout<<root->val<<" ";
        inorderTraversalOfBT(root->right);
    }
}
int main()
{
    vector<int>postoder={9,15,7,20,3};
    vector<int>inorder={9,3,15,20,7};

    TreeNode *root=buildTree(postoder,inorder);

    inorderTraversalOfBT(root);

    return 0;
}
