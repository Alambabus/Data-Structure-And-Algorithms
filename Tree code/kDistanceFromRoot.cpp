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

void countNodesHelper(TreeNode *root, int k,vector<int> &ans)
{
    //base case
    if(!root)return ;
    if(k==0)
    {
        ans.push_back(root->data);
        return ;
    }
    //recursive case
    countNodesHelper(root->left,k-1,ans);
    countNodesHelper(root->right,k-1,ans);
}

vector<int> Kdistance(TreeNode *root, int k)
{
  vector<int>ans;
  countNodesHelper(root,k,ans);
  return ans;
}



int main()
{

    TreeNode *root=NULL;

    root=createBinaryTreePreorder();

    int k=2;

    vector<int>ans=Kdistance(root,k);
    for(auto x:ans)cout<<x<<" ";


    return 0;
}
