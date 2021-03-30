//
//  2021-03-30
//  LeetCode
//  714. Best Time to Buy and Sell Stock with Transaction Fee
//  Accepted

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int i;
        int max_balance_after_buying;
        int yesterday, today;
        
        max_balance_after_buying = -prices[0] - fee;
        yesterday = 0;
        for (i = 1; i < prices.size(); ++i) {
            max_balance_after_buying = max(max_balance_after_buying, yesterday - prices[i] - fee);
            today = max(yesterday, max_balance_after_buying + prices[i]);
            
            yesterday = today;
        }
        
        return yesterday;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    
#if (EXAMPLE == 1)
    vector<int> prices{ 1, 3, 2, 8, 4, 9 };
    int fee = 2;
    // Output: 8
#elif (EXAMPLE == 2)
    vector<int> prices{ 1, 3, 7, 5, 10, 3 };
    int fee = 3;
    // Output: 6
#endif

    cout << "Output: " << s.maxProfit(prices, fee) << endl;

    return 0;
}
