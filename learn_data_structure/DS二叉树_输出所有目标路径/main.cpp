//
//  main.cpp
//  DS二叉树_输出所有目标路径
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
struct PathNode{
    TreeNode* node;
    int pathSum;
    PathNode(TreeNode* n,int s):node(n),pathSum(s){}
};
vector<vector<int>> Path(TreeNode* root,int targetSum)
{
    vector<vector<int>> result;
    if(!root)
    {
        return result;
    }
    stack<PathNode> nodeStack;
    stack<vector<int>> pathStack;
    
    nodeStack.push(PathNode(root, root->val));
    pathStack.push(vector<int>(1,root->val));
    
    while (!nodeStack.empty()) {
        PathNode current=nodeStack.top();
        nodeStack.pop();
        vector<int> currentPath=pathStack.top();
        pathStack.pop();
        TreeNode* node=current.node;
        int currentSum=current.pathSum;
        
        if(!node->left&&!node->right&&currentSum==targetSum)
        {
            result.push_back(currentPath);
        }
        if (node->right) {
            nodeStack.push(PathNode(node->right, currentSum + node->right->val));
            currentPath.push_back(node->right->val);
            pathStack.push(currentPath);
            currentPath.pop_back();
        }
        if(node->left)
        {
            nodeStack.push(PathNode(node->left, currentSum + node->left->val));
            currentPath.push_back(node->left->val);
            pathStack.push(currentPath);
            currentPath.pop_back();
            
        }
        
    }
    return result;
}
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
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int targetSum, n;
        cin >> targetSum >> n;
        vector<int> nums(n);
        for (int j = 0; j < n; j++) {
            cin >> nums[j];
        }

        TreeNode* root = buildTree(nums);
        vector<vector<int>> result = Path(root, targetSum);

        if (result.empty()) {
            cout << "Path not found" << endl;
        } else {
            for (vector<int> path : result) {
                for (int k = 0; k < path.size(); k++) {
                    cout << path[k];
                    if (k < path.size() - 1) {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }

        if (i < t - 1) {
            cout << endl;
        }
    }

    
    return 0;
}
