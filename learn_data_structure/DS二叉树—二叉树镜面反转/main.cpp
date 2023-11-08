//
//  main.cpp
//  DS二叉树—二叉树镜面反转
//
//  Created by Shockley on 11/1/23.
//

#include <iostream>
using namespace std;
struct TreeNode{
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val):data(val),left(nullptr),right(nullptr){}
};
TreeNode* buildBinaryTree(string &preorder,int &index)
{
    if(index>=preorder.length()||preorder[index]=='#')
    {
        index++;
        return nullptr;
    }
    TreeNode* node=new TreeNode(preorder[index++]);
    node->left=buildBinaryTree(preorder, index);
    node->right=buildBinaryTree(preorder, index);
    return node;
}

void mirrorTree(TreeNode* root)
{
    if(root==nullptr)
    {
        return ;
    }
    
    mirrorTree(root->left);
    mirrorTree(root->right);
    
    TreeNode* t=root->left;
    root->left=root->right;
    root->right=t;
}
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void levelorderTraversal(TreeNode* root,int level)
{
    if(root==nullptr)
        return ;
    if(level==1)
    {
        cout<<root->data<<" ";
    }
    else if(level>1)
    {
        levelorderTraversal(root->left, level-1);
        levelorderTraversal(root->right, level-1);
    }
        
}
int getHeight(TreeNode* node)
{
    if(node==nullptr)
        return 0;
    else{
        int leftHeight=getHeight(node->left);
        int rightHeight=getHeight(node->right);
        return (leftHeight>rightHeight)?(leftHeight+1):(rightHeight+1);
    }
}
void printLevelOrder(TreeNode* root) {
    int h = getHeight(root);
    for (int i = 1; i <= h; i++) {
        levelorderTraversal(root, i);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while (t--) {
        string preorder;
        cin>>preorder;
        int index=0;
        TreeNode* root=buildBinaryTree(preorder, index);
        if(root==nullptr)
        {
            cout << "NULL" << endl;
            cout << "NULL" << endl;
            cout << "NULL" << endl;
            cout << "NULL" << endl;
        }
        else {
            mirrorTree(root);
            preorderTraversal(root);
            cout << endl;
            inorderTraversal(root);
            cout << endl;
            postorderTraversal(root);
            cout << endl;
            printLevelOrder(root);
            cout << endl;
        }
    }
    return 0;
}
