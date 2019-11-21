#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (42.16%)
 * Total Accepted:    284.2K
 * Total Submissions: 674K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element
 * and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 *
 * You may imagine that nums[-1] = nums[n] = -∞.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2,
 * or index number 5 where the peak element is 6.
 *
 *
 * Note:
 *
 * Your solution should be in logarithmic complexity.
 *
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        return subroutine(nums, 0, n - 1);
    }

    int subroutine(vector<int> &nums, int s, int e) {
        if (s == e) {
            return s;
        }
        int mid = (s + e) / 2;
        if (nums[mid] > nums[mid + 1]) {
            return subroutine(nums, s, mid);
        }
        return subroutine(nums, mid + 1, e);
    }
};

// int main() {
//     Solution s;
//     vector<vector<int>> tests = {
//         {1}, // 0
//         {1, 2, 3, 1}, // 2
//         {1, 2, 1, 3, 5, 6, 4}, // 1, 5
//         {1, 3, 2, 1}, // 1
//         {1, 2, 3, 4, 3}, // 3
//         {3, 4, 3, 2, 1}, // 1
//     };
//     for (auto &v :tests) {
//         cout << s. findPeakElement(v) << endl;
//     }
//     return 0;
// }
