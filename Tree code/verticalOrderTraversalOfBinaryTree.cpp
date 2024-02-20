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

vector<vector<int>> verticalTraversal(TreeNode* root)
{
    vector<vector<int>>ans;
    queue<pair<TreeNode *,pair<int,int>>>q;
    map<int,map<int,multiset<int>>>m;
    if(!root)return ans;
    q.push({root,{0,0}});
    while(!q.empty())
    {
        auto x=q.front();
        q.pop();
        TreeNode *currNode=x.first;
        auto y=x.second;
        int vertical=y.first;
        int level=y.second;
        m[vertical][level].insert(currNode->data);
        if(currNode->left)q.push({currNode->left,{vertical-1,level+1}});
        if(currNode->right)q.push({currNode->right,{vertical+1,level+1}});
    }
    for(auto x:m)
    {
        vector<int>col;
        for(auto y:x.second)
        col.insert(col.end(),y.second.begin(),y.second.end());
        ans.push_back(col);
    }
    return ans;
}


int main()
{

    TreeNode *root=NULL;

    root=createBinaryTreePreorder();

    vector<vector<int>>ans=verticalTraversal(root);
    for(auto x:ans)
    {
        for(auto y:x)cout<<y<<" ";
        cout<<endl;
    }

    return 0;
}

