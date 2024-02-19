#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void helper(vector<vector<int>> &m,int row,int col,string path,vector<string> &paths,int n,vector<vector<int>> &isVisited)
{
    //base case
    if(row==n-1 && col==n-1)
    {
        paths.push_back(path);
        return ;
    }

    //recursive case
    //dounward
    if(row+1<n && !isVisited[row+1][col] && m[row+1][col]==1)
    {
        isVisited[row][col]=1;
        helper(m,row+1,col,path+'D',paths,n,isVisited);
        isVisited[row][col]=0;
    }
    //left
    if(col-1>=0 && !isVisited[row][col-1] && m[row][col-1]==1)
    {
        isVisited[row][col]=1;
        helper(m,row,col-1,path+'L',paths,n,isVisited);
        isVisited[row][col]=0;
    }
    //right
    if(col+1<n && !isVisited[row][col+1] && m[row][col+1]==1)
    {
        isVisited[row][col]=1;
        helper(m,row,col+1,path+'R',paths,n,isVisited);
        isVisited[row][col]=0;
    }
    //upward
    if(row-1>=0 && !isVisited[row-1][col] && m[row-1][col]==1)
    {
        isVisited[row][col]=1;
        helper(m,row-1,col,path+'U',paths,n,isVisited);
        isVisited[row][col]=0;
    }

}
vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    string path="";
    vector<string>paths;
    vector<vector<int>>isVisited(n,vector<int>(n,0));
    if(m[0][0]==1)
    helper(m,0,0,path,paths,n,isVisited);
    return paths;
}
int main()
{
    vector<vector<int>>m={{1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1}};
    int n=m.size();

    vector<string>paths=findPath(m,n);
    for(auto path:paths)cout<<path<<endl;

    return 0;
}
