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

void helper(TreeNode *root,int k,int &ans,int &cnt)
{
    //base case
    if(!root)return ;
    //recursive case
    helper(root->left,k,ans,cnt);
    if(ans != INT_MAX)return;
    cnt++;
    if(cnt==k)
    {
        ans=root->val;
        return ;
    }
    helper(root->right,k,ans,cnt);
}
int kthSmallest(TreeNode* root, int k)
{
    int ans=INT_MAX;
    int cnt=0;
    helper(root,k,ans,cnt);
    return ans;
}
int main()
{
    vector<int>pre={8,5,1,7,10,12};

    TreeNode *root=bstFromPreorder(pre);


    int ans=kthSmallest(root,3);
    cout<<ans<<endl;

    return 0;
}
