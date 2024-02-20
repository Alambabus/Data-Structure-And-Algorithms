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

pair<int,int> diameterOfBinaryTreeHelper(TreeNode *root)
{
    //base case
    if(!root)return {0,0};
    //recursive case
    pair<int,int>left=diameterOfBinaryTreeHelper(root->left);
    pair<int,int>right=diameterOfBinaryTreeHelper(root->right);
    int lD=left.first,rD=right.first;
    int lH=left.second,rH=right.second;
    return {max({lD,rD,lH+rH}),max(lH,rH)+1};
}
int diameterOfBinaryTree(TreeNode* root)
{
    pair<int,int>ans=diameterOfBinaryTreeHelper(root);
    return ans.first;
}



int main()
{

    TreeNode *root=NULL;

    root=createBinaryTreePreorder();

    int diaOfBT=diameterOfBinaryTree(root);

    cout<<diaOfBT<<endl;



    return 0;
}
