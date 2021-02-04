//
//  2020-02-04
//  LeetCode
//  669. Trim a Binary Search Tree
//  Accepted

#include <iostream>
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
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr || high < low)
            return nullptr;

        if (root->val < low)
            root = trimBST(root->right, low, high);
        else if (root->val > high)
            root = trimBST(root->left, low, high);
        else {
            root->left = trimBST(root->left, low, root->val - 1);
            root->right = trimBST(root->right, root->val + 1, high);
        }

        return root;
    }
};

#define EXAMPLE 1

#if (EXAMPLE == 1)
#define NODES 3
#define LOW 1
#define HIGH 2
#elif (EXAMPLE == 2)
#define NODES 5
#define LOW 1
#define HIGH 3
#elif (EXAMPLE == 3)
#define NODES 1
#define LOW 1
#define HIGH 2
#elif (EXAMPLE == 4)
#define NODES 2
#define LOW 1
#define HIGH 3
#elif (EXAMPLE == 5)
#define NODES 2
#define LOW 2
#define HIGH 4
#endif

int main() {
    TreeNode node[NODES];
    TreeNode* trimmed;
    Solution s;

#if (EXAMPLE == 1)
    node[0] = TreeNode(1, &node[1], &node[2]);
    node[1] = TreeNode(0);
    node[2] = TreeNode(2);
#elif (EXAMPLE == 2)
    node[0] = TreeNode(3, &node[1], &node[2]);
    node[1] = TreeNode(0, nullptr, &node[3]);
    node[2] = TreeNode(4);
    node[3] = TreeNode(2, &node[4], nullptr);
    node[4] = TreeNode(1);
#elif (EXAMPLE == 3)
    node[0] = TreeNode(1);
#elif (EXAMPLE == 4 || EXAMPLE == 5)
    node[0] = TreeNode(1, nullptr, &node[1]);
    node[1] = TreeNode(2);
#endif

    trimmed = s.trimBST(&node[0], LOW, HIGH);

    return 0;
}
