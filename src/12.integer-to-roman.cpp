#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 *
 * https://leetcode.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (52.31%)
 * Total Accepted:    270.3K
 * Total Submissions: 516.6K
 * Testcase Example:  '3'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 *
 *
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 *
 *
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 *
 *
 * Given an integer, convert it to a roman numeral. Input is guaranteed to be
 * within the range from 1 to 3999.
 *
 * Example 1:
 *
 *
 * Input: 3
 * Output: "III"
 *
 * Example 2:
 *
 *
 * Input: 4
 * Output: "IV"
 *
 * Example 3:
 *
 *
 * Input: 9
 * Output: "IX"
 *
 * Example 4:
 *
 *
 * Input: 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 *
 *
 * Example 5:
 *
 *
 * Input: 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 */
class Solution {
public:
    string intToRoman(int num) {
        char table[][4] = {
            {'I', 'V', 'X'},
            {'X', 'L', 'C'},
            {'C', 'D', 'M'},
            {'M',   0,  0 },
        };
        string s;
        while (num != 0) {
            s.insert(0, 1, num % 10 + '0');
            num /= 10;
        }
        int digit = s.size();
        string res;
        for (int i = 0; i < s.size(); ++i) {
            int c= s.size() - i - 1;
            int n = s[i] - '0';
            switch (n) {
            case 3:
            case 2:
            case 1: {
                int m = n;
                while (m > 0) {
                    res += table[c][0];
                    --m;
                }
                break;
            }
            case 4: {
                res += table[c][0];
                res += table[c][1];
                break;
            }
            case 5:
            case 6:
            case 7:
            case 8: {
                res += table[c][1];
                int m = n - 5;
                while (m > 0) {
                    res += table[c][0];
                    --m;
                }
                break;
            }
            case 9:
            {
                res += table[c][0];
                res += table[c][2];
                break;
            }
            default:
                break;
            }
        }
        return res;
    }
};

// int main() {
//     Solution s;
//     cout << s.intToRoman(9) << endl;
//     return 0;
// }