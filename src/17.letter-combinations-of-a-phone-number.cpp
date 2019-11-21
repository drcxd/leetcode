#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (43.76%)
 * Total Accepted:    478.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> r;
        if (digits.size() == 0) {
            return r;
        }
        int first = digits[0] - '0';
        for (char c : phone[first]) {
            string s;
            s.push_back(c);
            r.push_back(s);
        }
        for (int i = 1; i < digits.size(); ++i) {
            char d = digits[i];
            string &s = phone[d - '0'];
            vector<string> cr = r;
            r.clear();
            for (char c : s) {
                for (string t : cr) {
                    t.push_back(c);
                    r.push_back(t);
                }
            }
        }
        return r;
    }

private:
    map<int, string> phone = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"},
    };
};

// int main() {
//     Solution s;
//     string t = "23";
//     vector<string> r = s.letterCombinations(t);
//     for (auto &i : r) {
//         cout << i << endl;
//     }
//     return 0;
// }