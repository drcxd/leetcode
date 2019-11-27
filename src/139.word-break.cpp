#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* dynamic programming solution
 */
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> dict;
        for (const auto &s : wordDict) {
            dict.insert(s);
        }
        vector<bool> v(s.size() + 1, false);
        v[0] = true;
        for (int i = 1; i < v.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (v[j]) {
                    string sub = s.substr(j, i - j);
                    if (dict.find(sub) != dict.end()) {
                        v[i] = true;
                        break;
                    }
                }
            }
        }
        return v[v.size() - 1];
    }
};

/* Passed solution
 */
// class Solution {
// public:
//     bool wordBreak(string s, vector<string> &wordDict) {
//         unordered_set<string> dict;
//         for (const auto &s : wordDict) {
//             dict.insert(s);
//         }
//         return wordBreakRecursive(s, dict);
//     }

// private:
//     bool wordBreakRecursive(string s, unordered_set<string> &dict) {
//         if (s.size() == 0) {
//             return true;
//         }
//         for (int l = s.size(); l > 0; --l) {
//             string sub(s.begin(), s.begin() + l);
//             if (dict.find(sub) != dict.end()) {
//                 string copy = s;
//                 size_t pos = copy.find(sub);
//                 while (pos != string::npos &&
//                        (pos == 0 || pos + l == copy.size())) {
//                     copy.erase(copy.begin() + pos, copy.begin() + pos + l);
//                     pos = copy.find(sub);
//                 }
//                 if (wordBreakRecursive(copy, dict)) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

/* time cosumming solution
 */
// class Solution {
// public:
//     bool wordBreak(string s, vector<string> &wordDict) {
//         unordered_set<string> dict;
//         for (const auto &s : wordDict) {
//             dict.insert(s);
//         }
//         return wordBreakRecursive(s, 0, dict);
//     }

// private:
//     bool wordBreakRecursive(const string &s, int i, const unordered_set<string> &dict) {
//         if (i == s.size()) {
//             return true;
//         }
//         for (int l = s.size() - i; l > 0; --l) {
//             string sub(s.begin() + i, s.begin() + i + l);
//             if (dict.find(sub) != dict.end()) {
//                 if (wordBreakRecursive(s, i + l, dict)) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

int main() {
    Solution slt;
    // string s = "leetcode";
    string s = "abaabaa";
    vector<string> dict = {
        // "leet",
        // "code",
        // "cat",
        // "dog",
        // "catd",
        "ba",
        "aaa",
        "aa",
    };
    cout << slt.wordBreak(s, dict) << endl;
    return 0;
}