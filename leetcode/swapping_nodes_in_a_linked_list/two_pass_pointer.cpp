//
//  2021-03-15
//  LeetCode
//  1721. Swapping Nodes in a Linked List
//  Accepted

#include <iostream>
#include <vector>

using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* node;
        int count;
        int val, * valp;

        // First pass
        node = head;
        count = 0;
        while (node != nullptr) {
            ++count;
            if (count == k) {
                val = node->val;
                valp = &(node->val);
            }
            node = node->next;
        }

        // Second pass
        node = head;
        while (count > k) {
            --count;
            node = node->next;
        }
        *valp = node->val;
        node->val = val;

        return head;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    ListNode* result;
    int i;

#if (EXAMPLE == 1)
    vector<ListNode> nodes(5);
    int values[] = { 1, 2, 3, 4, 5 };
    int k = 2;
#elif (EXAMPLE == 2)
    vector<ListNode> nodes(10);
    int values[] = { 7, 9, 6, 6, 7, 8, 3, 0, 9, 5 };
    int k = 5;
#elif (EXAMPLE == 3)
    vector<ListNode> nodes(1);
    int values[] = { 1 };
    int k = 1;
#elif (EXAMPLE == 4)
    vector<ListNode> nodes(2);
    int values[] = { 1, 2 };
    int k = 1;
#elif (EXAMPLE == 5)
    vector<ListNode> nodes(3);
    int values[] = { 1, 2, 3 };
    int k = 2;
#endif

    for (i = 0; i < nodes.size() - 1; ++i) {
        nodes[i] = ListNode(values[i], &nodes[i + 1]);
    }
    nodes[i] = ListNode(values[i]);

    // Print inputs
    ListNode* node = &nodes[0];
    cout << "Input: head = [";
    while (node->next) {
        cout << node->val << ",";
        node = node->next;
    }
    cout << node->val << "], k = " << k << endl;

    result = s.swapNodes(&nodes[0], k);

    // Print outputs
    cout << "Output: [";
    while (result->next) {
        cout << result->val << ",";
        result = result->next;
    }
    cout << result->val << "]" << endl;

    return 0;
}
