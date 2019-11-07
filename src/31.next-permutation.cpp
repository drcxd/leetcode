#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.15%)
 * Total Accepted:    287.5K
 * Total Submissions: 918.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return;
        }
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                int j;
                for (j =  nums.size() - 1; j > i; --j) {
                    if (nums[j] > nums[i]) {
                        break;
                    }
                }
                swap(nums[j], nums[i]);
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};

// int main() {
//     Solution s;
//     // vector<int> nums = {1, 2, 3};
//     // vector<int> nums = {3, 2, 1};
//     vector<int> nums = {1, 1, 5};
//     s.nextPermutation(nums);
//     for (auto i : nums) {
//         cout << i << " ";
//     }
//     cout << endl;
//     return 0;
// }