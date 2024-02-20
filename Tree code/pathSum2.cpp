#include<iostream>
#include<vector>
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

void pathSumHelper(TreeNode *root,int tSum,vector<vector<int>> &ans,vector<int>t)
{
    //base case
    if(!root)return ;
    if(!root->left && !root->right && root->val==tSum)
    {
        t.push_back(root->val);
        ans.push_back(t);
        return;
    }
    t.push_back(root->val);
    pathSumHelper(root->left,tSum-root->val,ans,t);
    pathSumHelper(root->right,tSum-root->val,ans,t);
}
vector<vector<int>> pathSum(TreeNode* root, int tSum)
{
    vector<vector<int>>ans;
    vector<int>t;
    pathSumHelper(root,tSum,ans,t);
    return ans;
}


int main()
{
    TreeNode *root=createBinaryTreePreorder();

    int targetSum=22;
    vector<vector<int>>ans=pathSum(root,targetSum);


    for(auto x:ans)
    {
        for(auto y:x)cout<<y<<" ";
        cout<<endl;
    }


    return 0;
}
