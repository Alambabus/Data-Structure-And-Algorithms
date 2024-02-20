#include<iostream>
#include<queue>
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
TreeNode *buildLevelOrderBT()
{
    queue<TreeNode *>q;
    int n;
    cin>>n;
    if(n==-1)return NULL;
    TreeNode *root=new TreeNode(n);
    q.push(root);
    while(!q.empty())
    {
        TreeNode *currNode=q.front();
        q.pop();
        int c1,c2;
        cin>>c1;
        if(c1!=-1)
        {
            currNode->left=new TreeNode(c1);
            q.push(currNode->left);
        }
        cin>>c2;
        if(c2!=-1)
        {
            currNode->right=new TreeNode(c2);
            q.push(currNode->right);
        }
    }
    return root;
}
void inOrderTraversal(TreeNode *root)
{
    if(root)
    {
        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        inOrderTraversal(root->right);
    }
}

int main()
{
    TreeNode *root=NULL;

    root=buildLevelOrderBT();

    inOrderTraversal(root);

    return 0;
}
