#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (51.10%)
 * Total Accepted:    420.6K
 * Total Submissions: 813.4K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> r;
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); ++i) {
            if (candidates[i] > target) {
                break;
            } else if (candidates[i] == target) {
                vector<int> v = { candidates[i] };
                r.emplace_back(v);
            } else {
                vector<int> c(candidates.begin() + i, candidates.end());
                vector<vector<int>> s = combinationSum(c, target - candidates[i]);
                for (auto &v : s) {
                    v.push_back(candidates[i]);
                }
                r.insert(r.end(), s.begin(), s.end());
            }

        }
        return r;
    }
};

// int main() {
//     Solution s;
//     // vector<int> n = {2, 3, 5};
//     vector<int> n = { 2, 3, 6, 7 };
//     vector<vector<int>> r = s.combinationSum(n, 1);
//     for (auto &v : r) {
//         for (int i : v) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
// }