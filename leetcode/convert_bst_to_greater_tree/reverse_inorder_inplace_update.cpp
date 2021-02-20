//
//  2021-02-20
//  LeetCode
//  538. Convert BST to Greater Tree
//  Accepted (Runtime 95%, Memory 50%)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int sum;

    void reverseInorder(TreeNode* root) {
        if (root) {
            reverseInorder(root->right);
            sum += root->val;
            root->val = sum;
            reverseInorder(root->left);
        }
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        reverseInorder(root);
        return root;
    }
};

#define EXAMPLE 1

void printTreeNodes(string title, TreeNode* root, int node_size);

int main() {
    Solution s;

#if (EXAMPLE == 1)
    vector<TreeNode> nodes(9);
    nodes[0] = TreeNode(4, &nodes[1], &nodes[2]);
    nodes[1] = TreeNode(1, &nodes[3], &nodes[4]);
    nodes[2] = TreeNode(6, &nodes[5], &nodes[6]);
    nodes[3] = TreeNode(0);
    nodes[4] = TreeNode(2, nullptr, &nodes[7]);
    nodes[5] = TreeNode(5);
    nodes[6] = TreeNode(7, nullptr, &nodes[8]);
    nodes[7] = TreeNode(3);
    nodes[8] = TreeNode(8);
#elif (EXAMPLE == 2)
    vector<TreeNode> nodes(2);
    nodes[0] = TreeNode(0, nullptr, &nodes[1]);
    nodes[1] = TreeNode(1);
#elif (EXAMPLE == 3)
    vector<TreeNode> nodes(3);
    nodes[0] = TreeNode(1, &nodes[1], &nodes[2]);
    nodes[1] = TreeNode(0);
    nodes[2] = TreeNode(2);
#elif (EXAMPLE == 4)
    vector<TreeNode> nodes(4);
    nodes[0] = TreeNode(3, &nodes[1], &nodes[2]);
    nodes[1] = TreeNode(2, &nodes[3], nullptr);
    nodes[2] = TreeNode(4);
    nodes[3] = TreeNode(1);
#endif

    TreeNode* root;
    int n = nodes.size();

    if (n == 0) {
        root = nullptr;
    }
    else {
        root = &nodes[0];
    }

    printTreeNodes("Input", root, n);

    root = s.convertBST(root);

    printTreeNodes("Output", root, n);

    return 0;
}

void printTreeNodes(string title, TreeNode* root, int node_size) {
    queue<TreeNode*> q;

    cout << title << ": [";
    if (root) {
        q.push(root);
        while (!q.empty()) {
            if (q.front() == nullptr) {
                cout << "null";
            }
            else {
                --node_size;
                cout << q.front()->val;
                if (node_size == 0) {
                    break;
                }
                q.push(q.front()->left);
                q.push(q.front()->right);
            }
            cout << ",";
            q.pop();
        }
    }
    cout << "]" << endl;
}
