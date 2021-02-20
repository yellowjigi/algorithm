//
//  2021-02-20
//  LeetCode
//  138. Copy List with Random Pointer
//  Accepted (Runtime 40%, Memory 50%)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* Definition for a Node. */
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    vector<int> randoms; // for convenience to print out

    Node* copyRandomList(Node* head) {
        Node* node;
        vector<Node*> new_nodes;
        vector<int> randoms;
        unordered_map<Node*, int> hash_table;
        int i;

        if (head == NULL) {
            return NULL;
        }

        node = head;
        i = 0;
        while (node) {
            hash_table.insert({ node, i });
            new_nodes.push_back(new Node(node->val));
            node = node->next;
            ++i;
        }

        node = head;
        while (node) {
            if (node->random == NULL) {
                randoms.push_back(-1);
            }
            else {
                randoms.push_back(hash_table[node->random]);
            }
            node = node->next;
        }

        for (i = 0; i < new_nodes.size() - 1; ++i) {
            new_nodes[i]->next = new_nodes[i + 1];
            new_nodes[i]->random = randoms[i] == -1 ? NULL : new_nodes[randoms[i]];
        }
        new_nodes[i]->random = randoms[i] == -1 ? NULL : new_nodes[randoms[i]];

        this->randoms = randoms; // for convenience to print out
        return new_nodes[0];
    }
};

#define EXAMPLE 1

vector<int> buildRandoms(Node* node);
void printNodes(string title, Node* node, vector<int> randoms);

int main() {
    Solution s;
    Node* node;
    int i;

#if (EXAMPLE == 1)
    vector<Node> nodes{ Node(7), Node(13), Node(11), Node(10), Node(1) };
    vector<int> randoms{ -1, 0, 4, 2, 0 };
#elif (EXAMPLE == 2)
    vector<Node> nodes{ Node(1), Node(2) };
    vector<int> randoms{ 1, 1 };
#elif (EXAMPLE == 3)
    vector<Node> nodes{ Node(3), Node(3), Node(3) };
    vector<int> randoms{ -1, 0, -1 };
#elif (EXAMPLE == 4)
    vector<Node> nodes;
    vector<int> randoms;
#endif

    if (nodes.size() == 0) {
        node = NULL;
    }
    else {
        for (i = 0; i < nodes.size() - 1; ++i) {
            nodes[i].next = &nodes[i + 1];
            nodes[i].random = randoms[i] == -1 ? NULL : &nodes[randoms[i]];
        }
        nodes[i].random = randoms[i] == -1 ? NULL : &nodes[randoms[i]];
        node = &nodes[0];
    }

    printNodes("Input", node, randoms);

    node = s.copyRandomList(node);

    printNodes("Output", node, buildRandoms(node));

    return 0;
}

vector<int> buildRandoms(Node* head) {
    vector<int> randoms;
    Node* node, * random_pointer, * temp;
    int i;
	
    node = head;
    while (node) {
        random_pointer = node->random;
        if (random_pointer != NULL) {
            temp = node;
            node = head;
            i = 0;
            while (node != random_pointer) {
                node = node->next;
                ++i;
            }
            node = temp;

            randoms.push_back(i);
        }
        else {
            randoms.push_back(-1);
        }

        node = node->next;
    }

    return randoms;
}

void printNodes(string title, Node* head, vector<int> randoms) {
    Node* node = head;
    int i = 0;

    cout << title << ": [";
    while (node) {
        cout << "[" << node->val << ",";
        if (node->random) {
            cout << randoms[i];
        }
        else {
            cout << "null";
        }
        cout << "]";

        if (node->next) {
            cout << ",";
        }

        node = node->next;
        ++i;
    }
    cout << "]" << endl;
}
