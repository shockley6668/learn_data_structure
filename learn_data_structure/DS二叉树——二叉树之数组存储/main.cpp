//
//  main.cpp
//  DS二叉树——二叉树之数组存储
//
//  Created by Shockley on 10/19/23.
//

#include <iostream>
using namespace std;
struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):value(x),left(NULL),right(NULL){}
};
class BinaryTree{
private:
    
    int *preorder;
    int size;
public:
    
    BinaryTree(int *p,int s):preorder(p),size(s){}
    TreeNode* build(int index)
    {
        if(index>=size+1||preorder[index]==0)
        {
            return nullptr;
        }
        TreeNode* node=new TreeNode(preorder[index]);
        node->left=build(index*2);
        node->right=build(index*2+1);
        return node;
    }
  
    void preorderTraversal(TreeNode* node)
    {
        if(node==NULL)
            return;
        cout<<node->value<<" ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    
    while (t--) {
        int size=0;
        cin>>size;
        
        int* preorderlist=new int[size+1];
        
        for(int i=1;i<size+1;i++)
        {
            cin>>preorderlist[i];
        }
        BinaryTree bt(preorderlist, size);
        TreeNode* root;
        root=bt.build(1);
        bt.preorderTraversal(root);
        cout<<endl;
        delete[] preorderlist;

    }
    return 0;
}

/**********************************************************************
    Problem: 1065
    User: 202200202047
    Language: C++
    Result: AC
    Time:7 ms
    Memory:2228 kb
**********************************************************************/
