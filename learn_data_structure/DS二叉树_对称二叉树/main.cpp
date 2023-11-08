//
//  main.cpp
//  DS二叉树_对称二叉树
//
//  Created by Shockley on 11/6/23.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* buildTree(const vector<int>& arr)
{
    if(arr.empty() || arr[0]==-1)
        return nullptr;
    TreeNode* root =new TreeNode(arr[0]);
    queue <TreeNode*> q;
    q.push(root);
    int i = 1;  // position in array
    while (i < arr.size() && !q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != -1) {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1) {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}
bool isMirror(TreeNode* left,TreeNode* right)
{
    if(left==nullptr && right==nullptr)
        return true;
    if(!left||!right)
        return false;
    return (left->val==right->val)&&isMirror(left->left, right->right)&&isMirror(left->right, right->left);
}
bool isSymmetric(TreeNode* root)
{
    if(!root)
    {
        return true;
    }
    return isMirror(root->left, root->right);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++)
        {
            cin>>nums[i];
        }
        TreeNode* root=buildTree(nums);
        bool result=isSymmetric(root);
        if (result) 
        {
            cout << "true" << endl;
        } 
        else {
            cout << "false" << endl;
        }
    }
    return 0;
}
