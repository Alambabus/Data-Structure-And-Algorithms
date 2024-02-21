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
vector<int> inOrder(TreeNode* root)
{
    // Your code here
    if(!root)return {};
    vector<int>ans;
    stack<TreeNode*>s;
    TreeNode *node=root;
    while(true)
    {
        if(node!=NULL)
        {
            s.push(node);
            node=node->left;
        }
        else
        {
            if(s.empty())break;
            node=s.top();
            s.pop();
            ans.push_back(node->val);
            node=node->right;
        }
    }
    return ans;
}
int main()
{
    vector<int>pre={8,5,1,7,10,12};

    TreeNode *root=bstFromPreorder(pre);

    vector<int>ans=inOrder(root);

    for(auto x:ans)cout<<x<<" ";cout<<endl;


    return 0;
}
