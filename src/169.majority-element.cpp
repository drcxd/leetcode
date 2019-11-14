#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (54.38%)
 * Total Accepted:    459.9K
 * Total Submissions: 839.7K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // method 1: using map
        map<int, int> count;
        for (int i : nums) {
            if (count.find(i) != count.end()) {
                ++count[i];
            } else {
                count[i] = 1;
            }
        }
        int max;
        int max_count = 0;
        for (auto &it : count) {
            if (it.second > max_count) {
                max = it.first;
                max_count = it.second;
            }
        }
        // method 2: no map
        // sort(nums.begin(), nums.end());
        // return nums[nums.size() / 2];
        return max;
    }
};

// int main() {
//     Solution s;
//     vector<int> nums = { 3, 2, 3 };
//     cout << s.majorityElement(nums) << endl;
//     return 0;
// }
