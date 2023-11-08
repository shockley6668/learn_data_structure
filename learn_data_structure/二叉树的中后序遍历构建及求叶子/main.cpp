//
//  main.cpp
//  二叉树的中后序遍历构建及求叶子
//
//  Created by Shockley on 11/1/23.
//

#include <iostream>
#include <vector>

#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) {
        return nullptr;
    }

    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);

    int rootIndex = inStart;
    while (inorder[rootIndex] != rootVal) {
        rootIndex++;
    }

    int leftSize = rootIndex - inStart;

    root->left = buildTree(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    root->right = buildTree(inorder, postorder, rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);

    return root;
}

int findMinLeafValue(TreeNode* root) {
    if (!root) {
        return 999999;
    }

    if (!root->left && !root->right) {
        return root->val;
    }

    int leftMin = findMinLeafValue(root->left);
    int rightMin = findMinLeafValue(root->right);

    return min(leftMin, rightMin);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        vector<int> inorder(N);
        vector<int> postorder(N);

        for (int i = 0; i < N; i++) {
            cin >> inorder[i];
        }

        for (int i = 0; i < N; i++) {
            cin >> postorder[i];
        }

        TreeNode* root = buildTree(inorder, postorder, 0, N - 1, 0, N - 1);
        int minLeafValue = findMinLeafValue(root);
        cout << minLeafValue << endl;
    }

    return 0;
}

