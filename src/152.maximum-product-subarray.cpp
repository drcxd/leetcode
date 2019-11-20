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
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<vector<int>> intervals;
        vector<int> v;
        bool has_zero = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                has_zero = true;
                if (!v.empty()) {
                    intervals.push_back(v);
                    v.clear();
                }
            } else {
                v.push_back(nums[i]);
            }
        }
        if (!v.empty()) {
            intervals.push_back(v);
        }
        if (has_zero) {
            return max(maxInIntervals(intervals), 0);
        }
        return maxInIntervals(intervals);
    }

    int maxInIntervals(vector<vector<int>> &intervals) {
        vector<int> maxs;
        for (auto &v : intervals) {

            if (v.size() == 1) {
                maxs.push_back(v[0]);
                continue;
            }

            int left = -1, right = -1;
            int count = 0;
            for (int i = 0; i < v.size(); ++i) {
                if (v[i] < 0) {
                    if (left < 0) {
                        left = i;
                    }
                    if (i > right) {
                        right = i;
                    }
                    ++count;
                }
            }

            if (count % 2 == 0) {
                int r = 1;
                for (int i : v) {
                    r *= i;
                }
                maxs.push_back(r);
            } else {
                int r = 1, l = 1;
                for (int i = left + 1; i < v.size(); ++i) {
                    r *= v[i];
                }

                for (int i = 0; i < right; ++i) {
                    l *= v[i];
                }
                maxs.push_back(max(r, l));
            }
        }

        int real_max = maxs[0];
        for (int i = 1; i < maxs.size(); ++i) {
            if (maxs[i] > real_max) {
                real_max = maxs[i];
            }
        }
        return real_max;
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
