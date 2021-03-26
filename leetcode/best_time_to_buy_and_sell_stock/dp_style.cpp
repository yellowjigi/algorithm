//
//  2021-03-21
//  LeetCode
//  121. Best Time to Buy and Sell Stock
//  Accepted

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, max_profit, min_price;
        
        max_profit = 0;
        min_price = numeric_limits<int>::max();
        for (i = 0; i < prices.size(); ++i) {
            max_profit = max(max_profit, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        
        return max_profit;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    
#if (EXAMPLE == 1)
    vector<int> prices{ 7, 1, 5, 3, 6, 4 };
#elif (EXAMPLE == 2)
    vector<int> prices{ 7, 6, 4, 3, 1 };
#endif
    
    cout << "Output: " << s.maxProfit(prices) << endl;
    
    return 0;
}
