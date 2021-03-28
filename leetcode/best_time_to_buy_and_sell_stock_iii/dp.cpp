//
//  2021-03-29
//  LeetCode
//  123. Best Time to Buy and Sell Stock III
//  Accepted

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i;
        vector<vector<int>> dp(3, vector<int>(prices.size()));
        int max_balance_after_buying;

        // Maximum possible profits up to ith days with 0 transaction:
        // (dp[0][0], dp[0][1], ... dp[0][prices.size() - 1])
        // 0's. (Initialized to 0's.)
        
        // Maximum possible profits up to ith days with (at most) 1 transaction:
        // (dp[1][0], dp[1][1], ... dp[1][prices.size() - 1])
        max_balance_after_buying = -prices[0];
        dp[1][0] = 0;
        for (i = 1; i < prices.size(); ++i) {
            max_balance_after_buying = max(max_balance_after_buying, dp[0][i - 1] - prices[i]);
            dp[1][i] = max(dp[1][i - 1], max_balance_after_buying + prices[i]);
        }
        
        // Maximum possible profits up to ith days with (at most) 2 transactions:
        // (dp[2][0], dp[2][1], ... dp[2][prices.size() - 1])
        max_balance_after_buying = -prices[0];
        dp[2][0] = 0;
        for (i = 1; i < prices.size(); ++i) {
            max_balance_after_buying = max(max_balance_after_buying, dp[1][i - 1] - prices[i]);
            dp[2][i] = max(dp[2][i - 1], max_balance_after_buying + prices[i]);
        }
        
        // Return the maximum possible profit up to the last day with (at most) 2 transactions.
        return dp[2][prices.size() - 1];
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    
#if (EXAMPLE == 1)
    vector<int> prices{ 3, 3, 5, 0, 0, 3, 1, 4 };
    // Output: 6
#elif (EXAMPLE == 2)
    vector<int> prices{ 1, 2, 3, 4, 5 };
    // Output: 4
#elif (EXAMPLE == 3)
    vector<int> prices{ 7, 6, 4, 3, 1 };
    // Output: 0
#elif (EXAMPLE == 4)
    vector<int> prices{ 1 };
    // Output: 0
#endif
    
    cout << "Output: " << s.maxProfit(prices) << endl;
    
    return 0;
}
