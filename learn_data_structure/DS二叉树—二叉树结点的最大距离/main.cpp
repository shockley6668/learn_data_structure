#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int maxDistances[100];
char leftNodes[100];
char rightNodes[100];
int nodeCount = 0;

class BiTreeNode {
public:
    char data;
    BiTreeNode* left;
    BiTreeNode* right;

    BiTreeNode() {
        left = NULL;
        right = NULL;
    }

    ~BiTreeNode() {
        delete left;
        delete right;
    }
};

class BiTree {
public:
    BiTreeNode* root;
    int position;
    string treeString;
    int depth;
    int leftDepth;
    int rightDepth;
    char leftNodeData;
    char rightNodeData;
    char currentNodeData;
    int maxDistance;

    BiTree(string str) {
        position = 0;
        depth = 0;
        leftDepth = 0;
        rightDepth = 0;
        maxDistance = 0;
        treeString = str;
        root = createBiTree();
    }

    BiTreeNode* createBiTree() {
        char ch = treeString[position];
        position++;
        if (ch == '#') {
            return NULL;
        } else {
            BiTreeNode* node = new BiTreeNode();
            node->data = ch;
            node->left = createBiTree();
            node->right = createBiTree();
            return node;
        }
    }

    void countLeftDepth(BiTreeNode* node) {
        if (node->left == NULL) {
            leftDepth = 0;
            leftNodeData = node->data;
            return;
        }
        node = node->left;
        countDepth(node, 0);
        leftDepth = depth;
        leftNodeData = currentNodeData;
        return;
    }

    void countRightDepth(BiTreeNode* node) {
        if (node->right == NULL) {
            rightDepth = 0;
            rightNodeData = node->data;
            return;
        } else
            node = node->right;
        countDepth(node, 0);
        rightDepth = depth;
        rightNodeData = currentNodeData;
        return;
    }

    void countDepth(BiTreeNode* node, int i) {
        if (node) {
            i++;
            if (node->left == NULL && node->right == NULL) {
                if (depth < i) {
                    depth = i;
                    currentNodeData = node->data;
                }
            }
            countDepth(node->left, i);
            countDepth(node->right, i);
        }
    }

    void preOrder(BiTreeNode* node) {
        if (node != NULL) {
            depth = 0;
            countLeftDepth(node);
            depth = 0;
            countRightDepth(node);
            depth = 0;
            maxDistance = leftDepth + rightDepth;
            maxDistances[nodeCount] = maxDistance;
            leftNodes[nodeCount] = leftNodeData;
            rightNodes[nodeCount] = rightNodeData;
            nodeCount++;
            preOrder(node->left);
            preOrder(node->right);
        }
    }
};

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        for (int i = 0; i < nodeCount; i++)
            maxDistances[i] = 0;
        memset(leftNodes, 0, sizeof(leftNodes));
        memset(rightNodes, 0, sizeof(rightNodes));
        nodeCount = 0;
        string inputStr;
        cin >> inputStr;
        BiTree tree(inputStr);
        tree.preOrder(tree.root);
        int maxDistance = maxDistances[0];
        int index = 0;
        for (int i = 0; i < nodeCount; i++) {
            if (maxDistances[i] > maxDistance)
                index = i;
        }
        cout << maxDistances[index] << ":";
        if (maxDistances[index] != 0)
            cout << leftNodes[index] << " " << rightNodes[index] << endl;
        else
            cout << endl;
    }
    return 0;
}
