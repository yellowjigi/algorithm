//
//  2021-03-16
//  LeetCode
//  535. Encode and Decode TinyURL
//  Accepted

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

#define NUM_SYMBOLS 6

class Solution {
    const string domain = "http://tinyurl.com/";
    unordered_map<string, string> orig_to_base62, base62_to_orig;

    string decimalToBase62(int decimal) {
        stack<char> stack;
        int i, base10;
        char base62;
        string base62_full;

        for (i = decimal; i > 0; i /= 62) {
            base10 = i % 62;
            if (base10 >= 0 && base10 < 10) {
                // 0-9
                base62 = base10 + 48;
            }
            else if (base10 >= 10 && base10 < 36) {
                // A-Z
                base62 = base10 - 10 + 65;
            }
            else {
                // a-z
                base62 = base10 - 36 + 97;
            }

            stack.push(base62);
        }

        while (stack.size() < NUM_SYMBOLS) {
            stack.push('0');
        }

        while (!stack.empty()) {
            base62_full.push_back(stack.top());
            stack.pop();
        }

        return base62_full;
    }

public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        stringstream ss;
        string base62;

        if (orig_to_base62.find(longUrl) != orig_to_base62.end()) {
            base62 = orig_to_base62[longUrl];
        }
        else {
            base62 = decimalToBase62(orig_to_base62.size());

            orig_to_base62[longUrl] = base62;
            base62_to_orig[base62] = longUrl;
        }

        ss << domain << base62;

        return ss.str();
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string base62, orig;

        base62 = shortUrl.substr(domain.length());
        if (base62_to_orig.find(base62) != base62_to_orig.end()) {
            orig = base62_to_orig[base62];
        }

        return orig;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main() {
    Solution s;
    string url[3] = {
        "https://leetcode.com/problems/encode-and-decode-tinyurl/",
        "https://leetcode.com/problems/encode-and-decode-tinyurl/good",
        "https://leetcode.com/problems/encode-and-decode-tinyurl/bad"
    };

    for (int i = 0; i < 3; ++i) {
        cout << "URL: " << url[i] << endl;
        cout << "Encoded: " << s.encode(url[i]) << endl;
        cout << "Decoded: " << s.decode(s.encode(url[i])) << endl;
        cout << endl;
    }

    return 0;
}
