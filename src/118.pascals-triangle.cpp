#include <vector>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (48.20%)
 * Total Accepted:    302.8K
 * Total Submissions: 622.3K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; ++i) {
            vector<int> row;
            row.resize(i + 1);
            for (int j = 0; j < i + 1; ++j) {
                if (i > 0 && j > 0 && j < res[i - 1].size()) {
                    row[j] = res[i - 1][j - 1] + res[i - 1][j];
                } else {
                    row[j] = 1;
                }
            }
            res.push_back(row);

        }
        return res;
    }
};

// int main() {
//     Solution s;
//     vector<vector<int>> res = s.generate(6);
//     for (auto &r : res) {
//         for (auto i : r) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
