#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (40.98%)
 * Total Accepted:    209K
 * Total Submissions: 504.9K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if (m == 0) {
            return 0;
        }

        vector<int> v = triangle[0];
        for (int i = 1; i < m; ++i) {
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][triangle[i].size() - 1] += triangle[i - 1][triangle[i - 1].size() - 1];
            for (int j = 1; j < triangle[i].size() - 1; ++j) {
                triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
            // for (int j : triangle[i]) {
            //     cout << j << " ";
            // }
            // cout << endl << endl;
        }
        int min = triangle[m - 1][0];
        for (int i = 1; i < triangle[m - 1].size(); ++i) {
            if (triangle[m - 1][i] < min) {
                min = triangle[m - 1][i];
            }
        }
        return min;
    }
};

// int main() {
//     Solution s;
//     vector<vector<int>> triangle = {
//         {2},
//         {3,4},
//         {6,5,7},
//         {4,1,8,3},
//     };
//     cout << s.minimumTotal(triangle) << endl;
//     return 0;
// }