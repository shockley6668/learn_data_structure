//
//  main.cpp
//  DS二叉树——二叉树之父子结点
//
//  Created by Shockley on 10/18/23.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode{
    char value;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(char x):value(x),left(NULL),right(NULL),parent(NULL){}
};
class BinaryTree{
private:
    int index;
    string preorder;
public:
    vector<char> leaves;
    vector<char> parents;
    
    BinaryTree(const string &s):index(0),preorder(s){
        leaves.clear();
        parents.clear();
        
    }
    TreeNode* getTree()
    {
        index=0;
        return creatTree(nullptr);
    }
    TreeNode* creatTree(TreeNode* parent)
    {
        if(index>=preorder.size()||preorder[index]=='0')
        {
            index++;
            return nullptr;
        }
        TreeNode* node=new TreeNode(preorder[index++]);
        node->parent=parent;
        node->left=creatTree(node);
        node->right=creatTree(node);
        return node;
    }
    void findLeaveAndParent(TreeNode* node)
    {
        //跳出递归条件
        if(node==NULL)
        {
            return ;
        }
        //找到叶子节点
        if(node->left==NULL&&node->right==NULL)
        {
            //record the value of the leave node
            leaves.push_back(node->value);
            //record the value of the leaves parent
            if(node->parent)
            parents.push_back(node->parent->value);
            else
                parents.push_back(node->value);
        }
        //not leave
        findLeaveAndParent(node->left);
        findLeaveAndParent(node->right);
    }
    void printLeavesAndParent(TreeNode* root)
    {
        findLeaveAndParent(root);
        for(char leave :leaves)
        {
            cout<<leave<<" ";
        }
        cout<<endl;
        for(char parent:parents)
        {
            cout<<parent<<" ";
        }
        cout<<endl;
    }
    void fuckSztuNewOJ(TreeNode* root)
    {
        
        findLeaveAndParent(root);
        for(char leave :leaves)
        {
            cout<<leave<<" ";
        }
        cout<<endl;
        for(int i=0;i<parents.size()-1;i++)
        {
            cout<<parents[i]<<" ";
        }
        cout<<parents.at(parents.size()-1);
        
    }
    
}
;
int main()
{
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        BinaryTree bt(s);
        TreeNode *root;
        root=bt.getTree();
        bt.printLeavesAndParent(root);
        
    }
    return 0;
}


