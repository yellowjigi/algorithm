//
//  2021-02-21
//  LeetCode
//  242. Valid Anagram
//  Accepted

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        int i;

        for (i = 0; i < s.size(); ++i) {
            if (map.find(s[i]) == map.end()) {
                map.insert({ s[i], 1 });
            }
            else {
                map[s[i]] += 1;
            }
        }

        for (i = 0; i < t.size(); ++i) {
            if (map.find(t[i]) == map.end()) {
                return false;
            }
            else {
                map[t[i]] -= 1;
                if (map[t[i]] == 0) {
                    map.erase(t[i]);
                }
            }
        }

        if (!map.empty()) {
            return false;
        }

        return true;
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
