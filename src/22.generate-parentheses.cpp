#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (58.15%)
 * Total Accepted:    423.9K
 * Total Submissions: 728.7K
 * Testcase Example:  '3'
 *
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 *
 * For example, given n = 3, a solution set is:
 *
 *
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 *
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> r;
        vector<string> c;
        if (n == 0) {
            return r;
        }
        r.push_back(string(""));

        int rem = n * 2;
        while (rem > 0) {
            for (string &s : r) {
                if (num_of_char(s, ')') < num_of_char(s, '(')) {
                    if (num_of_char(s, '(') < n) {
                        string copy = s;
                        copy.push_back('(');
                        c.push_back(copy);
                    }
                    s.push_back(')');
                } else if (num_of_char(s, '(') < n) {
                    s.push_back('(');
                }
            }
            r.insert(r.begin(), c.begin(), c.end());
            c.clear();
            --rem;
        }

        return r;
    }

private:
    int num_of_char(const string &s, char t) {
        int count = 0;
        for (char c : s) {
            if (c == t) {
                ++count;
            }
        }
        return count;
    }
};

// int main() {
//     Solution s;
//     vector<string> r = s.generateParenthesis(3);
//     for (string &s : r) {
//         cout << s << endl;
//     }
//     return 0;
// }