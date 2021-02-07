//
//  2021-02-06
//  LeetCode
//  141. Linked List Cycle
//  Accepted

#include <iostream>
#include <vector>

using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        while (head != nullptr) {
            if (head->val == -100001) {
                return true;
            }
            head->val = -100001;
            head = head->next;
        }
        return false;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    int i;

#if (EXAMPLE == 1)
    vector<int> node_val{ 3, 2, 0, -4 };
    const int pos = 1;
#elif (EXAMPLE == 2)
    vector<int> node_val{ 1, 2 };
    const int pos = 0;
#elif (EXAMPLE == 3)
    vector<int> node_val{ 1 };
    const int pos = -1;
#endif

    vector<ListNode> nodes;
    nodes.reserve(node_val.size());
    nodes.push_back(ListNode(node_val[0]));
    for (i = 1; i < node_val.size(); i++) {
        nodes.push_back(ListNode(node_val[i]));
        nodes[i - 1].next = &nodes[i];
    }

    if (pos != -1) {
        nodes[i - 1].next = &nodes[pos];
    }

    cout << "Input: head = [";
    for (i = 0; i < nodes.size() - 1; i++) {
        cout << nodes[i].val << ",";
    }
    cout << nodes[i].val << "], pos = " << pos << endl;

    cout << "Output: ";
    if (s.hasCycle(&nodes[0])) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}
