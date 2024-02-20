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

bool isSameTree(TreeNode* p, TreeNode* q)
{
    //base case
    if(!p && !q)return true;
    if(!p || !q)return false;
    if(p->val != q->val)return false;
    //recursive case
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

int main()
{
    TreeNode *p=createBinaryTreePreorder();
    TreeNode *q=createBinaryTreePreorder();

    bool chk=isSameTree(p,q);
    if(chk)cout<<"True"<<endl;
    else cout<<"False"<<endl;

    return 0;
}
