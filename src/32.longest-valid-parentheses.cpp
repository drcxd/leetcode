#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (26.74%)
 * Total Accepted:    230.2K
 * Total Submissions: 860.5K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 *
 * Example 1:
 *
 *
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 *
 *
 * Example 2:
 *
 *
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 *
 *
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int no = 0, nc = 0;
        int max = 0;
        int l = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++no;
            } else {
                ++nc;
            }

            if (nc > no) {
                l = nc = no = 0;
            } else {
                ++l;
                if (nc == no) {
                    if (l > max) {
                        max = l;
                    }
                }
            }
        }

        no = nc = l = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++no;
            } else {
                ++nc;
            }
            if (nc > no) {
                l = nc = no = 0;
            } else {
                ++l;
                if (nc == no) {
                    if (l > max) {
                        max = l;
                    }
                }
            }
        }

        return max;
    }
};

// int main() {
//     Solution s;
//     vector<string> t = {
//         "(()", // 2
//         ")()())", // 4
//     };

//     for (string &str : t) {
//         cout << s.longestValidParentheses(str) << endl;
//     }
//     return 0;
// }