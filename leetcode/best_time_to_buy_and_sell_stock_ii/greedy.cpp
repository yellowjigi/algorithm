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
        int profit, max_profit;
        
        max_profit = 0;
        for (i = 0; i < prices.size() - 1; ++i) {
            profit = prices[i + 1] - prices[i];
            if (profit > 0) {
                max_profit += profit;
            }
        }

        return max_profit;
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
