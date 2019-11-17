#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (33.70%)
 * Total Accepted:    237.8K
 * Total Submissions: 704.4K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * 
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) {
            return 0;
        }

        int n = obstacleGrid[0].size();
        if (n == 0) {
            return 0;
        }

        vector<vector<long long>> s;

        for (auto &v : obstacleGrid) {
            vector<long long> nv;
            for (int &i : v) {
                nv.push_back(i > 0 ? -1 : i);
            }
            s.push_back(nv);
        }

        if (s[0][0]  || s[m - 1][n - 1] == -1) {
            return 0;
        }

        for (long long &i : s[0]) {
            if (i >= 0) {
                i = 1;
            } else {
                break;
            }
        }

        for (int i = 0; i < m; ++i) {
            if (s[i][0] >= 0) {
                s[i][0] = 1;
            } else {
                break;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (s[i][j] == -1) {
                    continue;
                }
                if (s[i - 1][j] != -1) {
                    s[i][j] += s[i - 1][j];
                }
                if (s[i][j - 1] != -1) {
                    s[i][j] += s[i][j - 1];
                }
            }
        }
        return s[m - 1][n - 1];
    }
};

// int main() {
//     Solution s;
//     vector<vector<int>> o = {
//         {0, 0, 0},
//         {0, 1, 0},
//         {0, 0, 0},
//         // {0, 0},
//         // {1, 1},
//         // {0, 0},
//     };
//     cout << s.uniquePathsWithObstacles(o) << endl;
//     return 0;
// }