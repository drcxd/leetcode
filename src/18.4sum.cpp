#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (31.62%)
 * Total Accepted:    273.5K
 * Total Submissions: 859.6K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> res;

        for (int i = 0; i < n - 3; ++i) {
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) {
                continue;
            }
            int target3 = target - nums[i];
            for (int j = i + 1; j < n - 2; ++j) {
                if (nums[j] + nums[j + 1] + nums[j + 2] > target3) {
                    break;
                }
                if (nums[j] + nums[n - 1] + nums[n - 2] < target3) {
                    continue;
                }
                int target2 = target3 - nums[j];
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    if (nums[left] + nums[right] == target2) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                        while (left < right && nums[left] == nums[left - 1]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right + 1]) {
                            --right;
                        }
                    } else if (nums[left] + nums[right] < target2) {
                        ++left;
                    } else {
                        --right;
                    }
                }
                while (j < n - 1 && nums[j] == nums[j + 1]) {
                    ++j;
                }
            }
            while (i < n - 1 && nums[i] == nums[i + 1]) {
                ++i;
            }
        }
        return res;
    }
};

// int main() {
//     Solution s;
//     vector<int> nums = {1, 0, -1, 0, -2, 2};
//     int target = 0;
//     vector<vector<int>> res = s.fourSum(nums, 0);
//     for (auto &i : res) {
//         for (auto j : i) {
//             cout << j << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }