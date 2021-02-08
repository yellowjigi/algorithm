//
//	2021-02-08
//	LeetCode
//	199. Binary Tree Right Side View
//	Accepted (Runtime 100%)

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
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> vals;
        size_t n;

        if (root == nullptr) {
            return vals;
        }

        q.push(root);
        while (!q.empty()) {
            vals.push_back(q.back()->val);
            n = q.size();
            while (n) {
                if (q.front()->left != nullptr) {
                    q.push(q.front()->left);
                }
                if (q.front()->right != nullptr) {
                    q.push(q.front()->right);
                }
                q.pop();
                --n;
            }
        }

        return vals;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    vector<int> vals;
    int i;

#if (EXAMPLE == 1)
    vector<TreeNode> nodes(5);
    nodes[0] = TreeNode(1, &nodes[1], &nodes[2]);
    nodes[1] = TreeNode(2, nullptr, &nodes[3]);
    nodes[2] = TreeNode(3, nullptr, &nodes[4]);
    nodes[3] = TreeNode(5);
    nodes[4] = TreeNode(4);
#elif (EXAMPLE == 2)
    vector<TreeNode> nodes(5);
    nodes[0] = TreeNode(1, &nodes[1], nullptr);
    nodes[1] = TreeNode(2, nullptr, &nodes[2]);
    nodes[2] = TreeNode(3, &nodes[3], nullptr);
    nodes[3] = TreeNode(4, nullptr, &nodes[4]);
    nodes[4] = TreeNode(5);
#elif (EXAMPLE == 3)
    vector<TreeNode> nodes(0);
#endif

    queue<TreeNode*> q;
    TreeNode* root;
    int n = nodes.size();
 
    cout << "Input: [";
    if (n == 0) {
        root = nullptr;
    }
    else {
        root = &nodes[0];
        q.push(root);
        while (!q.empty()) {
            if (q.front() == nullptr) {
                cout << "null";
            }
            else {
                --n;
                cout << q.front()->val;
                if (n == 0) {
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

    vals = s.rightSideView(root);

    cout << "Output: [";
    if (vals.size() != 0) {
        for (i = 0; i < vals.size() - 1; ++i) {
            cout << vals[i] << ", ";
        }
        cout << vals[i];
    }
    cout << "]" << endl;

    return 0;
}
