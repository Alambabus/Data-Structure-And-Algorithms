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

bool isSymmetricHelper(TreeNode *a,TreeNode *b)
{
    //base case
    if(!a && !b)return true;
    if(!a || !b)return false;
    if(a->val != b->val)return false;
    //recursive case
    return isSymmetricHelper(a->left,b->right) && isSymmetricHelper(a->right,b->left);
}
bool isSymmetric(TreeNode* root)
{
    if(!root)return true;
    bool ans=isSymmetricHelper(root->left,root->right);
    return ans;
}


int main()
{
    TreeNode *root=createBinaryTreePreorder();

    int chk=isSymmetric(root);

    if(chk)cout<<"Yes"<<endl;
    else cout<<"False"<<endl;

    return 0;
}
