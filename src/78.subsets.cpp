#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (55.49%)
 * Total Accepted:    443.6K
 * Total Submissions: 788.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> r;
        subroutine(nums, 0, r);
        r.push_back(vector<int>());
        // r.push_back(nums);
        return r;
    }
    void subroutine(vector<int>& nums, int start_index, vector<vector<int>> &r) {
        if (start_index == nums.size() - 1) {
            vector<int> v = {nums[start_index]};
            r.push_back(v);
        } else {
            subroutine(nums, start_index + 1, r);
            vector<vector<int>> nr = r;
            for (auto &v : nr) {
                v.push_back(nums[start_index]);
            }
            r.push_back(vector<int>(1, nums[start_index]));
            r.insert(r.end(), nr.begin(), nr.end());
        }
    }
};

// int main() {
//     Solution s;
//     vector<int> nums = { 1, 2, 3 };
//     vector<vector<int>> m = s.subsets(nums);
//     for (auto &v : m) {
//         for (int i : v) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }