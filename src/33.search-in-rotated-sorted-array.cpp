#include <vector>
#include <iostream>

using namespace std;
/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.23%)
 * Total Accepted:    510.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // first find the pivot
        int n = nums.size();
        if (n == 1) {
            if (nums[0] == target) {
                return 0;
            }
            return -1;
        } else if (n == 2) {
            if (nums[0] == target) {
                return 0;
            } else if (nums[1] == target) {
                return 1;
            }
            return -1;
        }
        int pivot_index = find_pivot(nums);
        int left = 0, right = n - 1;
        int middle;
        while (left <= right) {
            middle = (left + right) / 2;
            int v = nums[mod(middle + pivot_index, n)];
            if (v == target) {
                return mod(middle + pivot_index, n);
            } else if (target > v) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }

        }
        return -1;
    }

private:

    int mod(int n, int m) {
        return ((n % m) + m) % m;
    }

    int find_pivot(const vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        int middle;
        int pivot_index = -1;
        int n = nums.size();

        while (left <= right) {
            middle = (left + right) / 2;

            if (nums[middle] < nums[mod(middle - 1, n)] && nums[middle] < nums[mod(middle - 1, n)]) {
                pivot_index = middle;
                break;
            }
            if (nums[middle] > nums[mod(middle + 1, n)] && nums[middle] > nums[mod(middle - 1, n)]) {
                pivot_index = mod(middle + 1, n);
                break;
            }

            if (nums[middle] > nums[left] && nums[middle] < nums[right]) {
                right = middle - 1;
            } else if (nums[middle] > nums[left] && nums[middle] > nums[right]) {
                if (nums[left] < nums[right]) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            } else if (nums[middle] < nums[left] && nums[middle] < nums[right]) {
                if (nums[left] > nums[right]) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            }
        }
        return pivot_index;
    }
};

// int main() {
//     Solution s;
//     // vector<int> v1 = {0};
//     // vector<int> v2 = {0, 1};
//     // vector<int> v3 = {0, 1, 2};
//     // vector<int> v4 = {3, 0, 1, 2};
//     // vector<int> v5 = {2, 3, 0, 1};
//     // vector<int> v6 = {3, 5, 7, 0, 1, 2, 4};
//     // vector<vector<int>> vs;
//     // vs.push_back(v1);
//     // vs.push_back(v2);
//     // vs.push_back(v3);
//     // vs.push_back(v4);
//     // vs.push_back(v5);
//     // vs.push_back(v6);
//     // for (auto &v : vs) {
//     //     cout << s.search(v, 0) << endl;
//     // }
//     vector<int> v = { 5, 1, 2, 3, 4 };
//     cout << s.search(v, 4) << endl;
//     return 0;
// }