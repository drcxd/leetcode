#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Easy (53.25%)
 * Total Accepted:    396.8K
 * Total Submissions: 740.8K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times).
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit
 * = 5-1 = 4.
 * Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 =
 * 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        int max = 0;
        int low = prices[0];
        int high = prices[0];
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] > high) {
                high = prices[i];
            // } else if (prices[i] > low) {
            //     low = high = prices[i];
            } else {
                max += high - low;
                low = high = prices[i];
            }
        }
        if (high > low) {
            max += high - low;
        }
        return max;
    }
};

// int main() {
//     Solution s;
//     vector<int> prices = {2, 4, 1};
//     // vector<int> prices = { 1, 2, 3, 4, 5 };
//     // vector<int> prices = {7,1,5,3,6,4};
//     // vector<int> prices = {7, 6, 5, 3, 1};
//     cout << s.maxProfit(prices) << endl;
//     return 0;
// }