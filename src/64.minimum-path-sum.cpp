#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (48.93%)
 * Total Accepted:    278.3K
 * Total Submissions: 562.7K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }
        // int map[m][n];
        // memset(map, 0, sizeof(int) * m * n);
        // m[0][0] = grid[0][0];
        // for (int i = 1; i < n; ++i) {
        //     m[0][i] = grid[0]
        // }

        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
                
        //     }

        // }
        for (int i = 1; i < n; ++i) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};

// int main() {
//     Solution s;
//     vector<vector<int>> r = {
//         {1, 3, 1},
//         {1, 5, 1},
//         {4, 2, 1},
//     };
//     cout << s.minPathSum(r) << endl;
// }