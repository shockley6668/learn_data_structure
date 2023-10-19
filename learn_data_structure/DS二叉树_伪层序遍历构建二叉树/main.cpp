#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//使用队列存储。首先，将根节点放入队列。然后，每次从队列中取出一个节点，为其分配两个子节点（数组中的下两个元素），然后将这两个子节点加入到队列。如此重复，直到所有的节点都被处理。
TreeNode* buildTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
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

void preorderTraversal(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root) {
    if (!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        TreeNode* root = buildTree(arr);

        preorderTraversal(root);
        cout << endl;
        inorderTraversal(root);
        cout << endl;
        postorderTraversal(root);
        cout << endl;
        cout << endl;
    }

    return 0;
}
