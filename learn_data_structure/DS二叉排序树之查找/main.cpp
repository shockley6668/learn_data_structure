//
//  main.cpp
//  DS二叉排序树之查找
//
//  Created by Shockley on 12/13/23.
//

#include <iostream>
#include "vector"
using namespace::std;
struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v):value(v),left(nullptr),right(nullptr){}
};
TreeNode* binaryInsert(TreeNode* root,int val)
{
    if(root==NULL)
    {
        return new TreeNode(val);
    }
    if(val<root->value)
    {
        root->left=binaryInsert(root->left, val);
    }
    else if(val>root->value){
        root->right=binaryInsert(root->right, val);
    }
    return root;
    
}
void inorderSearch(TreeNode* root)
{
    if(root)
    {
        inorderSearch(root->left);
        cout<<root->value<<" ";
        inorderSearch(root->right);
    }
}
int binarysearch(TreeNode* root,int target,int depth=1)
{
    if(!root)
    {
        return -1;
    }
    if(root->value<target)
    {
        return binarysearch(root->right, target,depth+1);
    }
    else if(root->value>target)
    {
        return binarysearch(root->left, target,depth+1);
    }
    else{
        return depth;
    }
}
TreeNode* findmin(TreeNode* root)
{
    while (root->left) {
        root=root->left;
    }
    return root;
}
TreeNode* delet(TreeNode* root,int deletVal)
{
    if(!root)
    {
        return root;
    }
    if(deletVal<root->value)
    {
        root->left=delet(root->left,deletVal);
    }
    else if(deletVal>root->value)
    {
        root->right=delet(root->right,deletVal);
    }
    else{
        if(root->left==NULL)
        {
            TreeNode* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            TreeNode* temp=root->left;
            delete root;
            return temp;
        }
        TreeNode* temp=findmin(root->right);
        root->value=temp->value;
        root->right=delet(root->right, temp->value);
    }
    return root;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        TreeNode* root=NULL;
        int val;
        for(int i=0;i<n;i++)
        {
            
            cin>>val;
            root=binaryInsert(root, val);
        }
        inorderSearch(root);
        cout<<endl;
        int deletTime;
        cin>>deletTime;
        while (deletTime--) {
            int v;
            cin>>v;
            root=delet(root, v);
            inorderSearch(root);
            cout<<endl;
        }
    }
    return 0;
}
