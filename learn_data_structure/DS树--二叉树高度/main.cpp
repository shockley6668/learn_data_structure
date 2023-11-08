//
//  main.cpp
//  DS树--二叉树高度
//
//  Created by Shockley on 10/27/23.
//

#include <iostream>
#include <string>
using namespace std;
struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char v):val(v),left(nullptr),right(nullptr){}
};
TreeNode *buildBinaryTree(string &preorder,int &index)
{
    if(index>=preorder.length()||preorder[index]=='0')
    {
        index++;
        return nullptr;
    }
    TreeNode *root=new TreeNode(preorder[index++]);
    root->left=buildBinaryTree(preorder, index);
    root->right=buildBinaryTree(preorder,index);
    return root;
}
int calculateHeight(TreeNode *root)
{
    if(root==nullptr)
        return 0;
    int leftHeight=calculateHeight(root->left);
    int rightHeight=calculateHeight(root->right);
    return max(leftHeight, rightHeight)+1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    string preorder;
    for (int i=0; i<t; i++) {
        cin>>preorder;
        int index=0;
        TreeNode *root=buildBinaryTree(preorder,index);
        int height=calculateHeight(root);
        cout<<height<<endl;
    }
    return 0;
}
