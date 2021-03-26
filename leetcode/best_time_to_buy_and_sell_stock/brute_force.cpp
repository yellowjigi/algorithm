//
//  2021-03-21
//  LeetCode
//  121. Best Time to Buy and Sell Stock
//  Time Limit Exceeded (TLE)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, j, max_profit;
        
        max_profit = 0;        
        for (i = 0; i < prices.size() - 1; ++i) {
            for (j = i + 1; j < prices.size(); ++j) {
                max_profit = max(max_profit, prices[j] - prices[i]);
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
#elif (EXAMPLE == 2)
    vector<int> prices{ 7, 6, 4, 3, 1 };
#endif
    
    cout << "Output: " << s.maxProfit(prices) << endl;
    
    return 0;
}
