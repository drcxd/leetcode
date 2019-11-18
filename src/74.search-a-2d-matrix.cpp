#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (35.34%)
 * Total Accepted:    263.3K
 * Total Submissions: 741.6K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (!m) {
            return false;
        }
        int n = matrix[0].size();
        if (!n) {
            return false;
        }
        if (target < matrix[0][0]) {
            return false;
        }
        for (int i = 1; i < m; ++i) {
            if (target < matrix[i][0]) {
                return binarySearch(matrix[i - 1], target);
            }
        }
        return binarySearch(matrix[m - 1], target);
    }
    bool binarySearch(vector<int> &v, int target) {
        int left = 0, right = v.size() - 1, mid;
        if (target > v[right] || target < v[left]) {
            return false;
        }
        while (left <= right) {
            mid =  (left + right) / 2;
            if (v[mid] == target) {
                return true;
            } else if (v[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            };
        }
        return false;
    }
};

// int main() {
//     Solution s;
//     vector<vector<int>> matrix = {
//         {1,   3,  5,  7},
//         {10, 11, 16, 20},
//         {23, 30, 34, 50},
//     };
//     cout << s.searchMatrix(matrix, 3) << endl;
//     cout << s.searchMatrix(matrix, 13) << endl;
//     return 0;
// }