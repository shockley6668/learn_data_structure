//
//  main.cpp
//  DS二叉树--叶子数量
//
//  Created by Shockley on 10/18/23.
//

#include <iostream>
using namespace std;
struct TreeNode{
    char value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x):value(x),left(NULL),right(NULL){}
};
class BinaryTree{
private:
    int index;
    string preorder;
public:
    TreeNode* build(){
        if(index>=preorder.size()||preorder[index]=='0')
        {
            index++;
            return nullptr;
        }
        TreeNode* node=new TreeNode(preorder[index++]);
        node->left=build();
        node->right=build();
        return node;
    }
    int countLeave(TreeNode *node)
    {
        if(node==NULL)
            return 0;
        if(node->left==NULL &&node->right==NULL)
            return 1;
        return countLeave(node->left)+countLeave(node->right);
    }
    TreeNode* creatTree(string s)
    {
        preorder=s;
        index=0;
        return build();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    BinaryTree st;
    while (t--) {
        string s;
        cin>>s;
        TreeNode* root=st.creatTree(s);
        cout<<st.countLeave(root)<<endl;
    }
    return 0;
}
