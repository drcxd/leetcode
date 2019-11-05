#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.90%)
 * Total Accepted:    677.8K
 * Total Submissions: 2.7M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int sum, left, right;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            sum = 0 - nums[i];
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                if (left > i + 1 && nums[left] == nums[left - 1]) {
                    ++left;
                    continue;
                }
                if (right < nums.size() - 1 && nums[right] == nums[right + 1]) {
                    --right;
                    continue;
                }
                if (nums[left] + nums[right] == sum) {
                    vector<int> tri = { nums[i], nums[left], nums[right] };
                    res.push_back(tri);
                    ++left;
                    --right;
                } else if (nums[left] + nums[right] < sum) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    // vector<int> test = {-1, 0, 1, 2, -1, -4};
    // vector<int> test = {1, -1, -1, 0};
    // vector<int > test = {0, 0, 0, 0};
    vector<int> test = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
    vector<vector<int>> res = s.threeSum(test);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}