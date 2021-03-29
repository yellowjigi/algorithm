//
//  2021-03-29
//  LeetCode
//  423. Reconstruct Original Digits from English
//  Accepted

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    void decrementChars(unordered_map<char, int>& um, string s, int count) {
        for (char& c: s) {
            um[c] -= count;
        }
    }
    
public:
    string originalDigits(string s) {
        vector<int> count(10);
        unordered_map<char, int> um{
            {'e', 0}, {'f', 0}, {'g', 0},
            {'h', 0}, {'i', 0}, {'n', 0},
            {'o', 0}, {'r', 0}, {'s', 0},
            {'t', 0}, {'u', 0}, {'v', 0},
            {'w', 0}, {'x', 0}, {'z', 0}
        };
        int i, j;
        string result;
        
        for (char& c: s) {
            ++um[c];
        }

        // 'z'ero
        count[0] = um['z'];
        decrementChars(um, "zero", count[0]);

        // t'w'o
        count[2] = um['w'];
        decrementChars(um, "two", count[2]);
        
        // fo'u'r
        count[4] = um['u'];
        decrementChars(um, "four", count[4]);
        
        // si'x'
        count[6] = um['x'];
        decrementChars(um, "six", count[6]);
        
        // ei'g'ht
        count[8] = um['g'];
        decrementChars(um, "eight", count[8]);
        
        // 'o'ne
        count[1] = um['o'];
        decrementChars(um, "one", count[1]);
        
        // 't'hree
        count[3] = um['t'];
        decrementChars(um, "three", count[3]);
        
        // 'f'ive
        count[5] = um['f'];
        decrementChars(um, "five", count[5]);
        
        // 's'even
        count[7] = um['s'];
        decrementChars(um, "seven", count[7]);
        
        // n'i'ne
        count[9] = um['i'];
        decrementChars(um, "nine", count[9]);
        
        for (i = 0; i < 10; ++i) {
            for (j = 0; j < count[i]; ++j) {
                result += '0' + i;
            }
        }
        
        return result;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    
#if (EXAMPLE == 1)
    string str("owoztneoer");
#elif (EXAMPLE == 2)
    string str("fviefuro");
#endif

    cout << "Output: \"" << s.originalDigits(str) << "\"" << endl;
    
    return 0;
}
