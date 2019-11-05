#include <string>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (53.44%)
 * Total Accepted:    502.5K
 * Total Submissions: 940.2K
 * Testcase Example:  '"III"'
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
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 *
 * Example 1:
 *
 *
 * Input: "III"
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: "IV"
 * Output: 4
 *
 * Example 3:
 *
 *
 * Input: "IX"
 * Output: 9
 *
 * Example 4:
 *
 *
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 *
 *
 * Example 5:
 *
 *
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 */
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int c2i[128];
        c2i['I'] = 1;
        c2i['V'] = 5;
        c2i['X'] = 10;
        c2i['L'] = 50;
        c2i['C'] = 100;
        c2i['D'] = 500;
        c2i['M'] = 1000;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
            case 'C': {
                if (i + 1 < s.size() && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                    sum += (c2i[s[i + 1]] - c2i[s[i]]);
                    ++i;
                } else {
                    sum += (c2i[s[i]]);
                }
                break;
            }
            case 'X': {
                if (i + 1 < s.size() && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                    sum += (c2i[s[i + 1]] - c2i[s[i]]);
                    ++i;
                } else {
                    sum += (c2i[s[i]]);
                }
                break;
            }
            case 'I': {
                if (i + 1 < s.size() && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                    sum += (c2i[s[i + 1]] - c2i[s[i]]);
                    ++i;
                } else {
                    sum += (c2i[s[i]]);
                }
                break;
            }
            default: {
                sum += c2i[s[i]];
                break;
            }
            }
        }
        return sum;
    }
};

// int main() {
//     Solution s;
//     cout << s.romanToInt("MCMXCIV") << endl;
//     // cout << s.romanToInt("MCDLXXVI") << endl;
//     return 0;
// }