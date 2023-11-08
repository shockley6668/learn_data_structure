//
//  main.cpp
//  B : DS二叉树--层次遍历
//
//  Created by Shockley on 10/31/23.
//

#include <iostream>
#include <queue>
using namespace std;
struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char value):val(value),left(nullptr),right(nullptr){}
};
TreeNode* buildBinaryTree(string &preorder,int &index)
{
    if(index>=preorder.length()||preorder[index]=='0')
    {
        index++;
        return nullptr;
    }
    TreeNode *root=new TreeNode(preorder[index++]);
    root->left=buildBinaryTree(preorder, index);
    root->right=buildBinaryTree(preorder, index);
    return root;
}
void LevelOrderTarveral(TreeNode* root)
{
    if(root==nullptr)
        return ;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* current=q.front();
        q.pop();
        if(current->val!='0')
            cout<<current->val;
        if(current->left)
            q.push(current->left);
        if(current->right)
            q.push(current->right);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    string preorder;
    for(int i=0;i<t;i++)
    {
        cin>>preorder;
        int index=0;
        TreeNode* root=buildBinaryTree(preorder, index);
        LevelOrderTarveral(root);
        cout<<endl;
    }
    return 0;
}
