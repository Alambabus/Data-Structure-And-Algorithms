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

bool isLeafNode(TreeNode * &root)
{
    if(!root->left && !root->right)return true;
    return false;
}
void addLeftBoundary(TreeNode *root,vector<int> &ans)
{
    TreeNode *curr=root->left;
    while(curr)
    {
        if(!isLeafNode(curr))ans.push_back(curr->data);
        if(curr->left)curr=curr->left;
        else curr=curr->right;
    }
}
void  addRightBoundary(TreeNode *root,vector<int> &ans)
{
    TreeNode *curr=root->right;
    vector<int>t;
    while(curr)
    {
        if(!isLeafNode(curr))t.push_back(curr->data);
        if(curr->right)curr=curr->right;
        else curr=curr->left;
    }
    reverse(t.begin(),t.end());
    for(auto x:t)ans.push_back(x);
}

void addLeafNode(TreeNode *root,vector<int> &ans)
{
    //base case
    if(isLeafNode(root))
    {
        ans.push_back(root->data);
        return ;
    }
    //recursive case
    if(root->left)
    addLeafNode(root->left,ans);
    if(root->right)
    addLeafNode(root->right,ans);
}
vector<int> boundary(TreeNode *root)
{
    //Your code here
    vector<int>ans;
    if(!root)return ans;
    if(!isLeafNode(root))ans.push_back(root->data);
    addLeftBoundary(root,ans);
    addLeafNode(root,ans);
    addRightBoundary(root,ans);
    return  ans;
}


int main()
{

    TreeNode *root=NULL;

    root=createBinaryTreePreorder();

    vector<int>ans=boundary(root);
    for(auto x:ans)cout<<x<<" ";


    return 0;
}
