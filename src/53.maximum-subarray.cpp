#include <vector>
#include <iostream>

using namespace std;
/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (44.75%)
 * Total Accepted:    680.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int max = nums[0];
        int temp = max;
        for (int i = 1; i < nums.size(); ++i) {
            temp = temp + nums[i] > nums[i] ? temp + nums[i] : nums[i];
            if (temp > max) {
                max = temp;
            }
        }
        return max;
    }
};

// int main() {
//     Solution s;
//     // vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
//     // vector<int> nums = { 0 };
//     // vector<int> nums = {-1, -1, -2, -2};
//     vector<int> nums = { 8, -19, 5, -4, 20 };
//     cout << s.maxSubArray(nums) << endl;
//     return 0;
// }