#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (36.82%)
 * Total Accepted:    445K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> r;
        if (intervals.size() == 0) {
            return r;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int> &lhs, vector<int> &rhs) -> bool {
                                                     return lhs[0] < rhs[0];
                                                 });
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= end && end <= intervals[i][1] ||
                intervals[i][0] <= start && start <= intervals[i][1] ||
                start <= intervals[i][0] && intervals[i][0] <= end ||
                start <= intervals[i][1] && intervals[i][1] <= end) {
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            } else {
                vector<int> n = { start, end };
                r.push_back(n);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        vector<int> n = {start, end};
        r.push_back(n);
        return r;
    }

};

// int main() {
//     Solution s;
//     vector<vector<int>> intervals = {
//         // {1,3},{2,6},{8,10},{15,18}
//         // {1, 4}, {0, 4}
//         // {1, 4}, {0, 0}
//         // {1, 4}, {2, 3}
//         {2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}
//     };
//     vector<vector<int>> r = s.merge(intervals);
//     for (auto &v : r) {
//         for (int i : v) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }