//
//  2021-03-27
//  LeetCode
//  122. Best Time to Buy and Sell Stock II
//  Accepted

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i;
        int mp_ns; // Maximum profit with no stock
        int mp_s; // Maximum profit with a stock
        
        // Initial values
        mp_ns = 0;
        mp_s = -prices[0];
        for (i = 1; i < prices.size(); ++i) {
            // Calculate both of the cases:
            // 1) maximum possible profit with no stock in hand on the ith day
            mp_ns = max(mp_ns, mp_s + prices[i]);
            
            // 2) maximum possible profit with a stock in hand on the ith day
            mp_s = max(mp_s, mp_ns - prices[i]);
        }

        return mp_ns;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    
#if (EXAMPLE == 1)
    vector<int> prices{ 7, 1, 5, 3, 6, 4 };
    // Output: 7
#elif (EXAMPLE == 2)
    vector<int> prices{ 1, 2, 3, 4, 5 };
    // Output: 4
#elif (EXAMPLE == 3)
    vector<int> prices{ 7, 6, 4, 3, 1 };
    // Output: 0
#endif
    
    cout << "Output: " << s.maxProfit(prices) << endl;
    
    return 0;
}
