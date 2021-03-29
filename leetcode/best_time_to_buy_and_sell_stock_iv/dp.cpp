//
//  2021-03-29
//  LeetCode
//  188. Best Time to Buy and Sell Stock IV
//  Accepted

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int i, j;
        vector<vector<int>> dp(k + 1, vector<int>(prices.size())); // k + 1 including the case of 0 transaction
        int max_balance_after_buying;
        
        if (k == 0 || prices.size() == 0) {
            return 0;
        }
        
        for (i = 1; i <= k; ++i) {
            max_balance_after_buying = -prices[0];
            dp[i][0] = 0;
            for (j = 1; j < prices.size(); ++j) {
                max_balance_after_buying = max(max_balance_after_buying, dp[i - 1][j - 1] - prices[j]);
                dp[i][j] = max(dp[i][j - 1], max_balance_after_buying + prices[j]);
            }
        }
        
        return dp[k][prices.size() - 1];
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    
#if (EXAMPLE == 1)
    vector<int> prices{ 2, 4, 1 };
    int k = 2;
    // Output: 2
#elif (EXAMPLE == 2)
    vector<int> prices{ 3, 2, 6, 5, 0, 3 };
    int k = 7;
    // Output: 7
#endif

    cout << "Output: " << s.maxProfit(k, prices) << endl;

    return 0;
}
