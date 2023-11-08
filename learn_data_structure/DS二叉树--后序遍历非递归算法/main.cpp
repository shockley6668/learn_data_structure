//
//  main.cpp
//  DS二叉树--后序遍历非递归算法
//
//  Created by Shockley on 10/31/23.
//

#include <iostream>
#include "stack"
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
void postorderTraversal(TreeNode* root)
{
    if(root==nullptr)
        return ;
    stack<TreeNode *> S1;
    stack<int> S2;
    
    TreeNode* p=root;
    int tag;
    
    do{
        while (p!=nullptr) {
            S1.push(p);
            S2.push(0);
            p=p->left;
        }
        if(!S1.empty())
        {
            p=S1.top();
            S1.pop();
            
            tag=S2.top();
            S2.pop();
            if(tag==0)
            {
                S1.push(p);
                S2.push(1);
                p=p->right;
            }
            else{
                cout<<p->val;
                p=nullptr;
            }
        }
    }while(!S1.empty());
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    for (int i=0; i<t; i++) {
        string preorder;
        cin>>preorder;
        int index=0;
        TreeNode* root=buildBinaryTree(preorder, index);
        postorderTraversal(root);
        cout<<endl;
    }
    return 0;
}
