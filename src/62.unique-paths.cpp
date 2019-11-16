#include <algorithm>
#include <iostream>
using namespace std;

/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (49.49%)
 * Total Accepted:    355.8K
 * Total Submissions: 711.2K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 7, n = 3
 * Output: 28
 * 
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        int sum = 0;
        if (m > n) {
            swap(m, n);
        }
        if (m == 1) {
            return 1;
        }
        for (int i = 1; i <= m - 1; ++i) {
            int num_of_combination = choose_m_from_n(i - 1, m - 1 - 1);
            int num_of_placement = choose_m_from_n(i, n);
            sum += num_of_combination * num_of_placement;
        }
        return sum;
    }

    long long choose_m_from_n(int m, int n) {
        if (m > n) {
            swap(m, n);
        }
        long long n_descending_factorial = 1;
        long long m_factorial = 1;
        for (int i = n; i > n - m; --i) {
            n_descending_factorial *= i;
        }
        for (int i = m; i > 1; --i) {
            m_factorial *= i;
        }

        return n_descending_factorial / m_factorial;
    }
};

// int main() {
//     Solution s;
//     cout << s.uniquePaths(3, 2) << endl;
//     cout << s.uniquePaths(7, 3) << endl;
//     return 0;
// }