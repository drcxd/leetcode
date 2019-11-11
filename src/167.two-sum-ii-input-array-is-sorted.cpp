#include <vector>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (51.51%)
 * Total Accepted:    309K
 * Total Submissions: 596.6K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 * 
 * Note:
 * 
 * 
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v;
        int left = 0, right = numbers.size() - 1;
        while (true) {
            if (numbers[left] + numbers[right] == target) {
                v.push_back(left + 1);
                v.push_back(right + 1);
                break;
            } else if (numbers[left] + numbers[right] < target) {
                ++left;
            } else {
                --right;
            }
        }
        return v;
    }
};

// int main() {
//     Solution s;
//     vector<int> numbers = { 2, 7, 11, 15 };
//     vector<int> v = s.twoSum(numbers, 9);
//     for (int i : v) {
//         cout << i << " ";
//     }
//     cout << endl;
//     return 0;
// }