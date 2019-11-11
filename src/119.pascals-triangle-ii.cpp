#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (45.43%)
 * Total Accepted:    234K
 * Total Submissions: 510.6K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        for (int i = 0; i < rowIndex + 1; ++i) {
            v.push_back(1);
            for (int j = i - 1; j > 0; --j) {
                v[j] += v[j - 1];
            }
        }
        return v;
    }
};

// int main(int argc, char *argv[]) {
//     string str = argv[1];
//     Solution s;
//     vector<int> row = s.getRow(stoi(str));
//     for (auto i : row) {
//         cout << i << " ";
//     }
//     cout << endl;
//     return 0;
// }
