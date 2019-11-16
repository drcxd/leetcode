#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (32.66%)
 * Total Accepted:    326.8K
 * Total Submissions: 995.9K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = 0;
        while (!(nums[start] == 0 || start + nums[start] >= nums.size() - 1)) {
            int max = 0;
            int maxi = start;
            for (int i = start; i <= start + nums[start]; ++i) {
                if (nums[i] + i > max) {
                    max = nums[i] + i;
                    maxi = i;
                }
            }
            if (maxi == start) {
                return false;
            } else {
                start = maxi;
            }
        }
        return start + nums[start] >= nums.size() - 1;
    }
};

// int main() {
//     Solution s;
//     // vector<int> nums = { 2,3,1,1,4 };
//     vector<int> nums = {3,2,1,0,4};
//     cout << s.canJump(nums) << endl;
//     return 0;
// }