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

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>>ans;
        if(!root)return ans;
    queue<TreeNode *>q;
    q.push(root);
    int level=0;
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
        if(level%2==1)
        reverse(t.begin(),t.end());
        level++;
        ans.push_back(t);
    }
    return ans;
}

int main()
{

    TreeNode *root=NULL;

    root=createBinaryTreePreorder();

    vector<vector<int>>ans=zigzagLevelOrder(root);
    for(auto x:ans)
    {
        for(auto y:x)cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}
