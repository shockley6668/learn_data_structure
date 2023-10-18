//
//  main.cpp
//  DS二叉树—二叉树构建与遍历
//
//  Created by Shockley on 10/18/23.
//

#include <iostream>
using namespace std;
struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x):val(x),left(NULL),right(NULL){}
};
class BinaryTree{
private:
    int index;
    string preorder;
public:
    TreeNode* build(){
        if(index>=preorder.size()||preorder[index]=='#')
        {
            index++;
            return nullptr;
        }
        TreeNode* node=new TreeNode(preorder[index++]);
        node->left=build();
        node->right=build();
        return node;
    }
    void preorderTraversal(TreeNode* node)
    {
        if(node==NULL)
            return ;
        cout<<node->val;
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
    void inorderTraversal(TreeNode* node)
    {
        if(node==NULL)
        {
            return ;
        }
        inorderTraversal(node->left);
        cout<<node->val;
        inorderTraversal(node->right);
    }
    void postorderTraversal(TreeNode* node)
    {
        if(node==NULL)
            return ;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout<<node->val;
    }
    TreeNode* creatTree(string s){
        preorder=s;
        index=0;
        return  build();
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    BinaryTree bt;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        TreeNode* root=bt.creatTree(s);
        bt.preorderTraversal(root);
        cout<<endl;
        bt.inorderTraversal(root);
        cout<<endl;
        bt.postorderTraversal( root);
        cout<<endl;
    }
    return 0;
}
