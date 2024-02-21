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

bool helper(TreeNode *root,long LB,long RB)
{
    //base case
    if(!root)return true;
    if(root->val<LB  || root->val>RB)return false;
    //recursive case
    return helper(root->left,LB,(long)root->val-1) && helper(root->right,(long)root->val+1,RB);

}
bool isValidBST(TreeNode* root)
{
    long LB=INT_MIN;
    long RB=INT_MAX;
    return helper(root,LB,RB);
}
int main()
{
    vector<int>pre={8,5,1,7,10,12};

    TreeNode *root=bstFromPreorder(pre);

    inorderTraversalOfBST(root);

    return 0;
}
