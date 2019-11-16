#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (48.92%)
 * Total Accepted:    160.8K
 * Total Submissions: 322.9K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> r;
        if (n == 0) {
            return r;
        }
        r.resize(n);
        for (auto &v : r) {
            v.resize(n);
        }
        int start = 0;
        int i, j;
        int count = 1;
        while (start <= (n - 1) / 2) {
            i = j = start;
            while (j < n - start) {
                r[i][j++] = count++; // right
            }
            --j;
            ++i;
            if (i > n - 1 - start) {
                break;
            }
            while (i < n - start) {
                r[i++][j] = count++; // down
            }
            --i;
            --j;
            if (j < start) {
                break;
            }
            while (j > start) {
                r[i][j--] = count++; // left
            }
            while (i > start) {
                r[i--][j] = count++;
            }
            ++start;
        }
        return r;
    }
};

// int main() {
//     Solution s;
//     vector<vector<int>> r = s.generateMatrix(4);
//     for (auto &v : r) {
//         for (int i : v) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }