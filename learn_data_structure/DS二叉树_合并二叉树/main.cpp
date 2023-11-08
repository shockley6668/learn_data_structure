//
//  main.cpp
//  DS二叉树_合并二叉树
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
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1) {
        return t2;
    }
    if (!t2) {
        return t1;
    }
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}
// 前序遍历
void preorderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// 中序遍历
void inorderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// 后序遍历
void postorderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while (t--) {
        int n1,n2;
        cin>>n1;
        vector<int>nums1(n1);
        for(int i=0;i<n1;i++)
        {
            cin>>nums1[i];
        }
        cin>>n2;
        vector<int>nums2(n2);
        for(int i=0;i<n2;i++)
        {
            cin>>nums2[i];
        }
        TreeNode* tree1=buildTree(nums1);
        TreeNode* tree2=buildTree(nums2);
        TreeNode* mergetree=mergeTrees(tree1, tree2);
        preorderTraversal(mergetree);
        cout << endl;
        inorderTraversal(mergetree);
        cout << endl;
        postorderTraversal(mergetree);
        cout << endl;
        if (t!=0) {
            cout << endl;
        }
        
    }
    return 0;
}
