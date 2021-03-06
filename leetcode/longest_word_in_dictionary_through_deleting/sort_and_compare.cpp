//
//  2021-03-06
//  LeetCode
//  524. Longest Word in Dictionary through Deleting
//  Accepted

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    static bool comp(string s, string t) {
        if (s.length() == t.length()) {
            return s.compare(t) < 0;
        }
        return s.length() > t.length();
    }
    
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int i, j, k;

        sort(dictionary.begin(), dictionary.end(), comp);

        for (i = 0; i < dictionary.size(); ++i) {
            if (dictionary[i].length() > s.length()) {
                continue;
            }
            
            for (j = 0, k = 0; k < s.length(); ++k) {
                if (dictionary[i][j] == s[k]) {
                    ++j;
                    if (j == dictionary[i].length()) {
                        return dictionary[i];
                    }
                }
            }
        }

        return "";
    }
};

#define EXAMPLE 1

int main() {
    Solution s;

#if (EXAMPLE == 1)
    string str("abpcplea");
    vector<string> dictionary{ "ale", "apple", "monkey", "plea" };
#elif (EXAMPLE == 2)
    string str("abpcplea");
    vector<string> dictionary{ "a", "b", "c" };
#endif

    cout << "Output: \"" << s.findLongestWord(str, dictionary) << "\"" << endl;

    return 0;
}
