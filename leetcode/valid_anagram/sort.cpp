//
//  2021-02-21
//  LeetCode
//  242. Valid Anagram
//  Accepted

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s.compare(t) == 0 ? true : false;
    }
};

#define EXAMPLE 1

int main() {
    Solution sol;

#if (EXAMPLE == 1)
    string s("anagram");
    string t("nagaram");
#elif (EXAMPLE == 2)
    string s("rat");
    string t("car");
#endif

    cout << "Input: s = \"" << s << "\", t = \"" << t << "\"" << endl;

    cout << "Output: ";
    sol.isAnagram(s, t) ? cout << "true" : cout << "false";
    cout << endl;

    return 0;
}