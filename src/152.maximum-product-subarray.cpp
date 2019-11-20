#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (30.16%)
 * Total Accepted:    259.5K
 * Total Submissions: 854.3K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int cur = 1;
        for (int i = 0; i < nums.size(); ++i) {
            cur *= nums[i];
            res = max(cur, res);
            if (cur == 0) {
                cur = 1;
            }
        }

        cur = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            cur *= nums[i];
            res = max(cur, res);
            if (cur == 0) {
                cur = 1;
            }
        }
        return res;
    }
};

// int main() {
//     Solution s;
//     // vector<int> nums = {2,3,-2,4};
//     // vector<int> nums = { -2, 0, -1 };
//     // vector<int> nums = {0, 2};
//     // vector<int> nums = { 3, -1, 4 };
//     // vector<int> nums = { -4, -3 };
//     vector<int> nums = { 0 };
//     cout << s.maxProduct(nums) << endl;
//     return 0;
// }
