#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (31.65%)
 * Total Accepted:    286K
 * Total Submissions: 894.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> r;
        if (matrix.empty()) {
            return r;
        }
        int m = matrix.size(), n = matrix[0].size();
        int start = 0;
        int i, j;
        while (start <= (m - 1) / 2 && start <= (n - 1) / 2) {
            i = j = start;
            while (j < n - start) {
                r.push_back(matrix[i][j++]); // right
            }
            ++i;
            if (i > m - 1 - start) {
                break;
            }
            --j;

            while (i < m - start) {
                r.push_back(matrix[i++][j]); // down
            }
            --j;
            if (j < start) {
                break;
            }
            --i;

            while (j > start) {
                r.push_back(matrix[i][j--]); // left
            }

            while (i > start) {
                r.push_back(matrix[i--][j]); // right
            }
            ++start;
        }
        return r;
    }
    vector<int> spiralOrder1(vector<vector<int>>& matrix) {
        vector<int> r;
        if (matrix.empty()) {
            return r;
        }
        int top = 0, left = 0, bottom = matrix.size() - 1, right = matrix[0].size() - 1;
        int i = 0, j = 0;
        bool going_right = true, going_down = false, going_left = false, going_up = false;
        while (top <= bottom && left <= right) {
            if (top <= i && i <= bottom && left <= j && j <= right) {
                r.push_back(matrix[i][j]);
                if (going_right) {
                    ++j;
                } else if (going_down) {
                    ++i;
                } else if (going_left) {
                    --j;
                } else {
                    --i;
                }
            } else {
                if (going_right) {
                    --j;
                    going_right = false;
                    ++top;
                    going_down = true;
                    ++i;
                } else if (going_down) {
                    --i;
                    going_down = false;
                    --right;
                    going_left = true;
                    --j;
                } else if (going_left) {
                    ++j;
                    going_left = false;
                    --bottom;
                    going_up = true;
                    --i;
                } else {
                    ++i;
                    going_up = false;
                    ++left;
                    going_right = true;
                    ++j;
                }
            }
        }
        return r;
    }
};

// int main() {
//     Solution s;
//     vector<vector<int>> matrix = {
//         // {1, 2, 3 },
//         // {4, 5, 6 },
//         // {7, 8, 9 },
//         // {1, 2, 3, 4},
//         // {5, 6, 7, 8},
//         // {9,10,11,12},
//         {2, 5, 8},
//         {4, 0, -1},
//     };
//     vector<int> v = s.spiralOrder(matrix);
//     for (int i : v) {
//         cout << i << " ";
//     }
//     cout << endl;
//     return 0;
// }