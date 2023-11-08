//
//  main.cpp
//  DS树--带权路径和
//
//  Created by Shockley on 11/8/23.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* buildTree(string &preorder,int &index)
{
    char ch=preorder[index++];
    if(ch=='0')
    {
        return nullptr;
    }
    TreeNode* node=new TreeNode(ch);
    node->left=buildTree(preorder, index);
    node->right=buildTree(preorder, index);
    return node;
}

int calWpl(TreeNode* root,int depth,vector<int>& weight,int &wpl,int &index)
{

    if(!root->left&&!root->right&&isupper(root->val))
    {
        
        wpl+=depth*weight[index];
        index++;
    }
    if(root->left)
    {
        calWpl(root->left, depth+1, weight,wpl,index);
    }
    if(root->right)
    {
        calWpl(root->right, depth+1, weight,wpl,index);
    }
    return wpl;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while (t--) {
        string preorder;
        cin>>preorder;
        int n;
        cin>>n;
        vector<int> weight(n);
        for(int i=0;i<n;i++)
        {
            cin>>weight[i];
        }
        int index=0;
        int depth=0;
        int wpl=0;
        int index2=0;
        TreeNode* root=buildTree(preorder, index);
        int result=calWpl(root, depth, weight,wpl,index2);
        cout<<result;
        if(t!=0)
            cout<<endl;
    }
    return 0;
}
