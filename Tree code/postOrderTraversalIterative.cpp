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

vector<int> postorderTraversal(TreeNode* root)
{
    stack<TreeNode *>s1,s2;
    vector<int>ans;
    if(!root)return ans;
    s1.push(root);
    while(!s1.empty())
    {
        TreeNode *currNode=s1.top();
        s1.pop();
        s2.push(currNode);
        if(currNode->left)s1.push(currNode->left);
        if(currNode->right)s1.push(currNode->right);
    }
    while(!s2.empty())
    {
        ans.push_back(s2.top()->val);
        s2.pop();
    }
    return ans;
}
int main()
{
    vector<int>pre={8,5,1,7,10,12};

    TreeNode *root=bstFromPreorder(pre);

    vector<int>ans=postorderTraversal(root);

    for(auto x:ans)cout<<x<<" ";cout<<endl;


    return 0;
}
