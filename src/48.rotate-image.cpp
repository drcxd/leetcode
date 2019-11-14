#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (50.95%)
 * Total Accepted:    309.1K
 * Total Submissions: 598.4K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * You are given an n x n 2D matrix representing an image.
 * 
 * Rotate the image by 90 degrees (clockwise).
 * 
 * Note:
 * 
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 * 
 * Example 1:
 * 
 * 
 * Given input matrix = 
 * [
 * ⁠ [1,2,3],
 * ⁠ [4,5,6],
 * ⁠ [7,8,9]
 * ],
 * 
 * rotate the input matrix in-place such that it becomes:
 * [
 * ⁠ [7,4,1],
 * ⁠ [8,5,2],
 * ⁠ [9,6,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Given input matrix =
 * [
 * ⁠ [ 5, 1, 9,11],
 * ⁠ [ 2, 4, 8,10],
 * ⁠ [13, 3, 6, 7],
 * ⁠ [15,14,12,16]
 * ], 
 * 
 * rotate the input matrix in-place such that it becomes:
 * [
 * ⁠ [15,13, 2, 5],
 * ⁠ [14, 3, 4, 1],
 * ⁠ [12, 6, 8, 9],
 * ⁠ [16, 7,10,11]
 * ]
 * 
 * 
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0 || n == 1) {
            return;
        }
        int temp;
        int count = 0;
        for (int i = 0; i < n / 2; ++i) {
            ++count;
            for (int j = 0; j <  n - 1 - 2 * i; ++j) {
                // row from i ~ n-1-i
                // column from i ~ n-1-i
                temp = matrix[i][i + j];
                matrix[i][i + j] = matrix[n - 1 - i - j][i];
                matrix[n - 1 - i - j][i] = matrix[n - 1 - i][n - 1 - i - j];
                matrix[n - 1 - i][n - 1 - i - j] = matrix[i + j][n - 1 - i];
                matrix[i + j][n - 1 - i] = temp;
                // if (count == 2) {
                //     cout << "i " << i << " j " << j << endl;
                //     cout << "(i, j) " << i << " " << j << endl;
                //     cout << "(n-1-i-j, i) " << n-1-i-j << " " << i << endl;
                //     cout << "(n-1-i, n-1-i-j) " << n-1-i << " " << n-1-i-j << endl;
                //     cout << "(i+j, n-1-i) " << i+j << " " << n-1-i << endl;
                // }
            }
        }
    }
};

// int main() {
//     Solution s;
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9},
//     };
//     // vector<vector<int>> matrix = {
//     //     {1, 2},
//     //     {3, 4},
//     // };
//     // vector<vector<int>> matrix = {
//     //     {5, 1, 9,11},
//     //     {2, 4, 8,10},
//     //     {13, 3, 6, 7},
//     //     {15,14,12,16},
//     // };
//     s.rotate(matrix);
//     for (auto &v : matrix) {
//         for (int i : v) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }