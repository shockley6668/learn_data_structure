//
//  main.cpp
//  DS二叉树_另一棵树的子树
//
//  Created by Shockley on 11/7/23.
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
bool areIdentical(TreeNode* root1,TreeNode* root2)
{
    if(!root1&&!root2)
    {
        return true;
    }
    if(!root1||!root2)
    {
        return false;
    }
    return (root1->val==root2->val)&&(areIdentical(root1->left, root2->left))&&(areIdentical(root1->right, root2->right));
}
bool isSubTree(TreeNode* tree,TreeNode* subTree)
{
    if(!tree)
    {
        return false;
    }
    if(areIdentical(tree, subTree))
    {
        return true;
    }
    return isSubTree(tree->left, subTree)||isSubTree(tree->right,subTree);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while (t--) {
        int n1,n2;
        cin>>n1;
        vector<int> nums1(n1);
        
        for(int i=0;i<n1;i++)
        {
            cin>>nums1[i];
        }
        cin>>n2;
        vector<int> nums2(n2);
        for(int i=0;i<n2;i++)
        {
            cin>>nums2[i];
        }
        TreeNode* tree=buildTree(nums1);
        TreeNode* subTree=buildTree(nums2);
        bool result=isSubTree(tree, subTree);
        if(result)
        {
            cout << "true";
        }
        else{
            cout << "false";
        }
        if(t!=0)
        {
            cout<<endl;
        }
    }
    return 0;
}
