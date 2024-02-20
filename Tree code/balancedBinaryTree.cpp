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

pair<bool,int> isBalancedHelper(TreeNode *root)
{
    //base case
    if(!root)return {true,0};
    //recursive case
    pair<bool,int>left=isBalancedHelper(root->left);
    pair<bool,int>right=isBalancedHelper(root->right);
    bool isBalLeft=left.first,isBalRight=right.first;
    int lH=left.second,rH=right.second;
    if(isBalLeft && isBalRight && abs(lH-rH)<=1)return {true,max(lH,rH)+1};
    return {false,max(lH,rH)+1};
}


bool isBalanced(TreeNode* root)
{
    pair<bool,int>ans=isBalancedHelper(root);
    return ans.first;
}



int main()
{

    TreeNode *root=NULL;

    root=createBinaryTreePreorder();

    bool chk=isBalanced(root);
    if(chk)cout<<"Balanced"<<endl;
    else cout<<"UnBalanced"<<endl;



    return 0;
}
