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
int idx=0;
TreeNode *helper(int s,int e,vector<int>& pr, vector<int>& in)
{
    //base case
    if(s>e)return NULL;
    //recursive case
    int k=-1;
    int val=pr[idx++];
    for(int i=s;i<=e;i++)
    {
        if(val==in[i])
        {
            k=i;
            break;
        }
    }
    TreeNode *root=new TreeNode(in[k]);
    root->left=helper(s,k-1,pr,in);
    root->right=helper(k+1,e,pr,in);
    return root;
}
TreeNode* buildTree(vector<int>& pr, vector<int>& in)
{
    int n=pr.size();
    TreeNode *root=helper(0,n-1,pr,in);
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
    vector<int>preoder={3,9,20,15,7};
    vector<int>inorder={9,3,15,20,7};

    TreeNode *root=buildTree(preoder,inorder);

    inorderTraversalOfBT(root);

    return 0;
}
