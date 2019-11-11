#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (48.38%)
 * Total Accepted:    632.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (i.e., buy
 * one and sell one share of the stock), design an algorithm to find the
 * maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * 
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int low = prices[0];
        int high = prices[0];
        int max = high - low;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1] && prices[i] > high) {
                high = prices[i];
            } else if (prices[i] <= prices[i - 1] && prices[i] < low){
                if (high - low > max) {
                    max = high - low;
                }
                low = high = prices[i];
            }
        }
        if (high - low > max) {
            max = high - low;
        }
        return max;

    }
};

// int main(int argc, char* argv[]) {
//     Solution s;
//     vector<vector<int>> prices = {
//         {7,1,5,3,6,4},
//         {7, 6, 4, 3, 1},
//         {1, 2, 3, 2, 5},
//         {2, 4, 1},
//     };
//     // vector<int> prices = {7,1,5,3,6,4};
//     // vector<int> prices = {7, 6, 4, 3, 1};
//     // vector<int> prices = {1, 2, 3, 2, 5};
//     for (auto &i : prices) {
//         cout << s.maxProfit(i) << endl;
//     }
//     return 0;
// }