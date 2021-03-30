//
//  2021-03-30
//  LeetCode
//  309. Best Time to Buy and Sell Stock with Cooldown
//  Accepted

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i;
        int max_balance_after_buying;
        vector<int> dp(prices.size());
        
        if (prices.size() < 2) {
            return 0;
        }
        
        max_balance_after_buying = max(-prices[0], -prices[1]);
        dp[0] = 0;
        dp[1] = max(dp[0], max_balance_after_buying + prices[1]);
        for (i = 2; i < prices.size(); ++i) {
            max_balance_after_buying = max(max_balance_after_buying, dp[i - 2] - prices[i]);
            dp[i] = max(dp[i - 1], max_balance_after_buying + prices[i]);
        }
        
        return dp[prices.size() - 1];
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    
#if (EXAMPLE == 1)
    vector<int> prices{ 1, 2, 3, 0, 2 };
    // Output: 3
#elif (EXAMPLE == 2)
    vector<int> prices{ 1 };
    // Output: 0
#endif

    cout << "Output: " << s.maxProfit(prices) << endl;

    return 0;
}
