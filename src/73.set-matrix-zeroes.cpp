#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (41.01%)
 * Total Accepted:    250.8K
 * Total Submissions: 607K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */
class Solution {
public:
    // O(m + n) space
    // void setZeroes(vector<vector<int>>& matrix) {
    //     vector<int> row;
    //     vector<int> col;
    //     for (int i = 0; i < matrix.size(); ++i) {
    //         for (int j = 0; j < matrix[i].size(); ++j) {
    //             if (matrix[i][j] == 0) {
    //                 row.push_back(i);
    //                 col.push_back(j);
    //             }
    //         }
    //     }
    //     for (int i : row) {
    //         fill(matrix[i].begin(), matrix[i].end(), 0);
    //     }
    //     for (int i : col) {
    //         for (int j = 0; j < matrix.size(); ++j) {
    //             matrix[j][i] = 0;
    //         }
    //     }
    // }
    // O(1) space
    void setZeroes(vector<vector<int>> &matrix) {
        bool row = false, col = false;
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                col = true;
            }
        }

        for (int i = 0; i < matrix[0].size(); ++i) {
            if (matrix[0][i] == 0) {
                row = true;
            }
        }

        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < matrix[i].size(); ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix[0].size(); ++i) {
            if (matrix[0][i] == 0) {
                for (int j = 0; j < matrix.size(); ++j) {
                    matrix[j][i] = 0;
                }
            }
        }

        if (row) {
            for (int i = 0; i < matrix[0].size(); ++i) {
                matrix[0][i] = 0;
            }
        }
        if (col) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

// int main() {
//     Solution s;
//     vector<vector<int>> matrix = {
//         {0, 1, 2, 0},
//         {3, 4, 5, 2},
//         {1, 2, 1, 5},
//     };
//     s.setZeroes(matrix);
//     for (auto &v : matrix) {
//         for (int i : v) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }