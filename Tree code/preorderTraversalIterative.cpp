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
vector<int> preorderTraversal(TreeNode* root)
{
    if(!root)return {};
    stack<TreeNode *>s;
    vector<int>ans;
    s.push(root);
    while(!s.empty())
    {
        TreeNode *currNode=s.top();
        s.pop();
        ans.push_back(currNode->val);
        if(currNode->right)s.push(currNode->right);
        if(currNode->left)s.push(currNode->left);
    }
    return ans;
}
int main()
{
    vector<int>pre={8,5,1,7,10,12};

    TreeNode *root=bstFromPreorder(pre);

    vector<int>ans=preorderTraversal(root);

    for(auto x:ans)cout<<x<<" ";cout<<endl;


    return 0;
}
