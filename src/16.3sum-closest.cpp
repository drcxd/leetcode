#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.74%)
 * Total Accepted:    394.6K
 * Total Submissions: 863.1K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum;
        int closest = nums[0] + nums[1] + nums[nums.size() - 1];
        int delta = abs(target - (nums[0] + nums[1] + nums[nums.size() - 1]));
        int left, right;
        for (int i = 0; i < nums.size(); ++i) {
            sum = target - nums[i];
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                int new_delta = abs(sum - (nums[left] + nums[right]));
                if (new_delta < delta) {
                    delta = new_delta;
                    closest = nums[i] + nums[left] + nums[right];
                }
                if (nums[left] + nums[right] > sum) {
                    --right;
                } else if (nums[left] + nums[right] < sum) {
                    ++left;
                } else {
                    return closest;
                }
            }
        }
        return closest;
    }
};

// int main() {
//     Solution s;
//     // vector<int> nums = {-1, 2, 1, -4};
//     vector<int> nums = {0, 0, 0};
//     int target = 1;
//     cout << s.threeSumClosest(nums, target) << endl;
//     return 0;
// }