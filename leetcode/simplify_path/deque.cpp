//
//	2021-02-07
//	LeetCode
//	71. Simplify Path
//	Accepted (Runtime 90%, Memory 95%)

#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> dq;
        size_t i, begin;
        string token, cano_path;

        for (begin = 1; begin < path.length(); begin = i + 1) {
            i = path.find('/', begin);
            if (i == string::npos) {
                i = path.length();
            }

            token = path.substr(begin, i - begin);
            if (token.compare("..") == 0) {
                if (!dq.empty()) {
                    dq.pop_back();
                }
            }
            else if (token.compare(".") != 0 && token.length() != 0) {
                dq.push_back(token);
            }
        }

        while (!dq.empty()) {
            cano_path.push_back('/');
            cano_path.append(dq.front());
            dq.pop_front();
        }

        if (cano_path.length() == 0) {
            cano_path.push_back('/');
        }
        
        return cano_path;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
#if (EXAMPLE == 1)
    string path("/home/");
#elif (EXAMPLE == 2)
    string path("/../");
#elif (EXAMPLE == 3)
    string path("/home//foo/");
#elif (EXAMPLE == 4)
    string path("/a/./b/../../c/");
#elif (EXAMPLE == 5)
    string path("/a//b////c/d//././/..");
#endif

    cout << s.simplifyPath(path) << endl;

    return 0;
}
