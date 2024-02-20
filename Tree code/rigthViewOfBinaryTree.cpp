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

void helper(TreeNode *root,int level,vector<int> &ans)
{
    //base case
    if(!root)return ;
    //recursive case
    if(ans.size()==level)ans.push_back(root->data);
    helper(root->right,level+1,ans);
    helper(root->left,level+1,ans);
}
vector<int> rightSideView(TreeNode* root)
{
    vector<int>ans;
    helper(root,0,ans);
    return ans;
}


int main()
{

    TreeNode *root=NULL;

    root=createBinaryTreePreorder();

    vector<int>ans=rightSideView(root);
    for(auto x:ans)cout<<x<<" ";

    return 0;
}
