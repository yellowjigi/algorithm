//
//  2021-03-09
//  LeetCode
//  895. Maximum Frequency Stack
//  Accepted

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class FreqStack {
    unordered_map<int, int> um;
    vector<stack<int>> stacks;
    int max_freq;

public:
    FreqStack(): max_freq(0) {

    }

    void push(int val) {
        int freq;

        if (um.find(val) == um.end()) {
            um.insert({ val, 0 });
        }

        freq = ++um[val];
        if (freq > max_freq) {
            ++max_freq;
            stacks.push_back(stack<int>());
        }

        stacks[freq - 1].push(val);
    }

    int pop() {
        int temp = stacks[max_freq - 1].top();

        stacks[max_freq - 1].pop();
        if (stacks[max_freq - 1].empty()) {
            stacks.pop_back();
            --max_freq;
        }

        if (--um[temp] == 0) {
            um.erase(temp);
        }

        return temp;
    }
};

#define EXAMPLE 1

int main() {
    FreqStack obj;
    int i;
    
#if (EXAMPLE == 1)
    vector<int> inputs{ 5, 7, 5, 7, 4, 5 };
    const int pop_num = 4;
#endif

    for (i = 0; i < inputs.size(); ++i) {
        obj.push(inputs[i]);
    }

    cout << "Output" << endl << "[";
    for (i = 0; i < pop_num - 1; ++i) {
        cout << obj.pop() << ", ";
    }
    cout << obj.pop() << "]";

    return 0;
}