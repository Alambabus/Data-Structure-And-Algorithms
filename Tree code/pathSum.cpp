
#include<iostream>
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

bool hasPathSum(TreeNode* root, int tSum)
{
    //base case
    if(!root)return false;
    if(!root->left && !root->right)return tSum==root->val;
    //recursive case
    return hasPathSum(root->left,tSum-root->val) || hasPathSum(root->right,tSum-root->val);
}


int main()
{
    TreeNode *root=createBinaryTreePreorder();

    int targetSum=22;
    bool chk=hasPathSum(root,targetSum);

    if(chk)cout<<"True"<<endl;
    else cout<<"False"<<endl;


    return 0;
}
