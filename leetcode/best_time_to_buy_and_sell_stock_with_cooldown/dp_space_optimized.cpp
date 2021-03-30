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
        int day_before_yesterday, yesterday, today;
        
        if (prices.size() < 2) {
            return 0;
        }
        
        max_balance_after_buying = max(-prices[0], -prices[1]);
        day_before_yesterday = 0;
        yesterday = max(day_before_yesterday, max_balance_after_buying + prices[1]);
        for (i = 2; i < prices.size(); ++i) {
            max_balance_after_buying = max(max_balance_after_buying, day_before_yesterday - prices[i]);
            today = max(yesterday, max_balance_after_buying + prices[i]);
            
            day_before_yesterday = yesterday;
            yesterday = today;
        }
        
        // Think of `today` at this point as the `prices.size()`th day.
        // What we need is `prices.size() - 1`th day.
        return yesterday;
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
