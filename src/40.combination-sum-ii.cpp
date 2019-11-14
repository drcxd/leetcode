#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (43.79%)
 * Total Accepted:    263.5K
 * Total Submissions: 595.2K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> r = subroutine(candidates, 0, target);
        return r;
    }

    vector<vector<int>> subroutine(vector<int>& candidates, int start_index, int target) {
        vector<vector<int>> r;
        for (int i = start_index; i < candidates.size(); ++i) {
            if (i > start_index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > target) {
                break;
            } else if (candidates[i] == target) {
                vector<int> v = { candidates[i] };
                r.emplace_back(v);
            } else {
                // vector<int> c(candidates.begin() + i + 1, candidates.end());
                vector<vector<int>> s = subroutine(candidates, i + 1, target - candidates[i]);
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
//     // vector<int> c = { 10,1,2,7,6,1,5 };
//     vector<int> c = { 2, 5, 2, 1, 2 };
//     vector<vector<int>> r = s.combinationSum2(c, 5);
//     for (auto &v : r) {
//         for (int i : v) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }