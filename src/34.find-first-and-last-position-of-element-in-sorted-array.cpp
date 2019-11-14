#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (34.34%)
 * Total Accepted:    376.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        if (nums.size() == 0) {
            v = {-1, -1};
            return v;
        }
        int left = 0, right = nums.size() - 1;
        int mid;
        int min_index = -1;
        int max_index = -1;
        bool found = false;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                found = true;
            }
            if (!found) {
                if (nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] == target && mid == 0 ||
                    nums[mid] == target && nums[mid - 1] != target) {
                    min_index = mid;
                    // cout << min_index << endl;
                    break;
                } else if (nums[mid] == target) {
                    right = mid - 1;
                } else if (nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
         }

        if (found) {
            left = min_index;
            right = nums.size() - 1;
            while (left <= right) {
                mid = (left + right) / 2;
                if (nums[mid] == target && mid == nums.size() - 1 ||
                    nums[mid] == target && nums[mid + 1] != target) {
                    max_index = mid;
                    // cout << max_index << endl;
                    break;
                } else if (nums[mid] == target) {
                    left = mid + 1;
                } else if (nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        v = {min_index, max_index};
        return v;
    }
};

// int main() {
//     Solution s;
//     // vector<int> nums = { 5,7,7,8,8,10 };
//     vector<int> nums = { };
//     vector<int> v = s.searchRange(nums, 1);
//     for (int i : v) {
//         cout << i << " ";
//     }
//     cout << endl;
//     return 0;
// }