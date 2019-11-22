#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (50.75%)
 * Total Accepted:    437K
 * Total Submissions: 860.1K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 *
 * Example:
 *
 *
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 *
 * Note:
 *
 *
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 *
 *
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > str2v;
        vector<vector<string> > anagrams;
        for (const auto &s : strs) {
            string std = toStandard(s);
            if (str2v.find(std) != str2v.end()) {
                str2v[std].push_back(s);
            } else {
                str2v[std] = { s };
            }
        }
        for (auto &e : str2v) {
            anagrams.push_back(e.second);
        }
        return anagrams;
    }

private:

    string toStandard(const string &s) {
        int counter[26] = { 0 };
        for (char c : s) {
            ++counter[c - 'a'];
        }
        string r;
        for (int i = 0; i < 26; ++i) {
            r += string(counter[i], 'a' + i);
        }
        return r;
    }
};

// int main() {
//     Solution s;
//     vector<string> strs = {
//         "eat","tea","tan","ate","nat","bat",
//     };
//     vector<vector<string> > a = s.groupAnagrams(strs);
//     for (auto &v : a) {
//         for (auto &s : v) {
//             cout << s << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }