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
vector <int> bottomView(TreeNode *root) {
    vector<int>ans;
    if(!root)return ans;
    queue<pair<TreeNode *,int>>q;
    q.push({root,0});
    map<int,int>m;
    while(!q.empty())
    {
        auto temp=q.front();
        q.pop();
        TreeNode *currNode=temp.first;
        int level=temp.second;
        m[level]=currNode->data;
        if(currNode->left)q.push({currNode->left,level-1});
        if(currNode->right)q.push({currNode->right,level+1});
    }
    for(auto x:m)
    ans.push_back(x.second);
    return ans;
}


int main()
{

    TreeNode *root=NULL;

    root=createBinaryTreePreorder();

    vector<int>ans=bottomView(1root);
    for(auto x:ans)cout<<x<<" ";

    return 0;
}
