/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (43.86%)
 * Total Accepted:    343.4K
 * Total Submissions: 783K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 * 
 * 
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int middle;
        int pivot_index = -1;
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

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
        return nums[pivot_index];
    }
    int mod(int n, int m) {
        return ((n % m) + m) % m;
    }
};
