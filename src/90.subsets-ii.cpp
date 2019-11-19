#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (43.92%)
 * Total Accepted:    234.3K
 * Total Submissions: 528.3K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> r;
        sort(nums.begin(), nums.end());
        subroutine(nums, 0, r);
        r.push_back(vector<int>());
        set<vector<int>> s(r.begin(), r.end());
        r.clear();
        r.insert(r.begin(), s.begin(), s.end());
        return r;
    }

private:
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

int main() {
    Solution s;
    // vector<int> nums = { 1, 2, 2 };
    vector<int> nums = { 4, 4, 4, 1, 4};
    vector<vector<int>> r = s.subsetsWithDup(nums);
    for (auto &v : r) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}