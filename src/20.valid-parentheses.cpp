/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.57%)
 * Total Accepted:    758.8K
 * Total Submissions: 2M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push_back(c);
            } else {
                if (stack.empty()) {
                    return false;
                }
                if (c == ')' && stack.back() != '(') {
                    return false;
                }
                if (c == ']' && stack.back() != '[') {
                    return false;
                }
                if (c == '}' && stack.back() != '{') {
                    return false;
                }
                stack.pop_back();
            }
        }
        return stack.empty();
        // int o1 = 0, c1 = 0, o2 = 0, c2 = 0, o3 = 0, c3 = 0;
        // for (char c : s) {
        //     switch (c) {
        //     case '(': {
        //         ++o1;
        //         break;
        //     }
        //     case ')': {
        //         ++c1;
        //         break;
        //     }
        //     case '{': {
        //         ++o2;
        //         break;
        //     }
        //     case '}': {
        //         ++c2;
        //         break;
        //     }
        //     case '[': {
        //         ++o3;
        //         break;
        //     }
        //     case ']': {
        //         ++c3;
        //         break;
        //     }
        //     default:
        //         break;
        //     }
        //     if (c1 > o1 || c2 > o2 || c3 > o3) {
        //         return false;
        //     }
        // }
        // return c1 == o1 && c2 == o2 && c3 == o3;
    }
};
