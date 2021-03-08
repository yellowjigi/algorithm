//
//  2021-03-08
//  LeetCode
//  895. Maximum Frequency Stack
//  Time Limit Exceeded (TLE)

#include <algorithm>
#include <iostream>
#include <deque>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class FreqStack {
    vector<int> v;
    unordered_map<int, int> um;
    static bool comp(pair<int, int> const& p1, pair<int, int> const& p2) {
        return p1.second > p2.second;
    };

public:
    FreqStack() {

    }

    void push(int val) {
        if (um.find(val) == um.end()) {
            um.insert({ val, 1 });
        }
        else {
            ++um[val];
        }
        v.push_back(val);
    }

    int pop() {
        vector<int>::reverse_iterator rit, temp_rit;
        vector<pair<int, int>> sorted = vector<pair<int, int>>(um.begin(), um.end());
        int temp, i;

        sort(sorted.begin(), sorted.end(), comp);

        rit = find(v.rbegin(), v.rend(), sorted[0].first);
        for (i = 1; i < sorted.size(); ++i) {
            if (sorted[i].second < sorted[i - 1].second) {
                break;
            }
            temp_rit = find(v.rbegin(), v.rend(), sorted[i].first);
            if (temp_rit < rit) {
                rit = temp_rit;
            }
        }

        temp = *rit;
        if (--um[temp] == 0) {
            um.erase(temp);
        }
        v.erase((rit + 1).base());

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