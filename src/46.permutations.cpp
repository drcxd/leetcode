#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (58.60%)
 * Total Accepted:    468.8K
 * Total Submissions: 799.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 *
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 *
 *
 */
class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > p;
        sub(nums, 0, p);
        return p;
    }

private:

    void sub(vector<int> &nums, int s, vector<vector<int> > &p) {
        if (s == nums.size()) {
            p.push_back(nums);
        }
        for (int i = s; i < nums.size(); ++i) {
            swap(nums[i], nums[s]);
            sub(nums, s + 1, p);
            swap(nums[i], nums[s]);
        }
    }
};

// int main() {
//     Solution s;
//     vector<int> nums = { 1, 2, 3 };
//     vector<vector<int> > p = s.permute(nums);
//     for (auto &v : p) {
//         for (int i : v) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }