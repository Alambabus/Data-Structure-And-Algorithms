#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    int val;
    TreeNode *right;
    TreeNode(int data)
    {
        this->left=NULL;
        this->val=data;
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

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>>ans;
        if(!root)return ans;
    queue<TreeNode *>q;
    q.push(root);
    while(!q.empty())
    {
        int sz=q.size();
        vector<int>t;
        for(int i=0;i<sz;i++)
        {
            TreeNode* currNode=q.front();
            q.pop();
            t.push_back(currNode->data);
            if(currNode->left)q.push(currNode->left);
            if(currNode->right)q.push(currNode->right);
        }
        ans.push_back(t);
    }
    return ans;
}

int main()
{

    TreeNode *root=NULL;

    root=createBinaryTreePreorder();

    vector<vector<int>>ans=levelOrder(root);
    for(auto x:ans)
    {
        for(auto y:x)cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}
