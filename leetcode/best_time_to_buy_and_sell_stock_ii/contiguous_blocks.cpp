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
        int i, n;
        int buy, sell;
        int max_profit;
        
        i = 0;
        n = prices.size();
        max_profit = 0;
        while (i < n - 1) {
            // Contiguous descending block
            while (i < n - 1 && prices[i] >= prices[i + 1]) {
                ++i;
            }
            buy = prices[i];
            
            // Contiguous ascending block
            while (i < n - 1 && prices[i] < prices[i + 1]) {
                ++i;
            }
            sell = prices[i];
            
            max_profit += sell - buy;
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
