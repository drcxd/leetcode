#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (32.57%)
 * Total Accepted:    354.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m == 0) {
            return false;
        }
        int n = board[0].size();
        if (n == 0) {
            return false;
        }
        if (word.empty()) {
            return true;
        }
        vector<vector<char>> flag;
        for (auto & v : board) {
            vector<char> nv;
            for (char c : v) {
                nv.push_back(0);
            }
            flag.push_back(nv);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    flag[i][j] = 1;
                    if (subroutine(board, i, j, word, 1, flag)) {
                        return true;
                    } else {
                        flag[i][j] = 0;
                    }
                }
            }
        }

        return false;
    }

private:
    bool subroutine(vector<vector<char>> &board, int i, int j, string &word, int s, vector<vector<char>> &flag) {
        if (s == word.size()) {
            return true;
        }
        int m = board.size(), n = board[0].size();
        if (i - 1 >= 0 && flag[i - 1][j] != 1 && board[i - 1][j] == word[s]) {
            flag[i - 1][j] = 1;
            if (subroutine(board, i - 1, j, word, s + 1, flag)) {
                return true;
            } else {
                flag[i - 1][j] = 0;
            }
        }
        if (i + 1 < m && flag[i + 1][j] != 1 && board[i + 1][j] == word[s]) {
            flag[i + 1][j] = 1;
            if (subroutine(board, i + 1, j, word, s + 1, flag)) {
                return true;
            } else {
                flag[i + 1][j] = 0;
            }
        }
        if (j - 1 >= 0 && flag[i][j - 1] != 1 && board[i][j - 1] == word[s]) {
            flag[i][j - 1] = 1;
            if (subroutine(board, i, j - 1, word, s + 1, flag)) {
                return true;
            } else {
                flag[i][j - 1] = 0;
            }
        }
        if (j + 1 < n && flag[i][j + 1] != 1 && board[i][j + 1] == word[s]) {
            flag[i][j + 1] = 1;
            if (subroutine(board, i, j + 1, word, s + 1, flag)) {
                return true;
            } else {
                flag[i][j + 1] = 0;
            }
        }
        return false;
    }
};

// int main() {
//     Solution s;
//     vector<vector<char>> board = {
//         {'A','B','C','E'},
//         {'S','F','C','S'},
//         {'A','D','E','E'},
//     };
//     cout << s.exist(board, "ABCCED") << endl;
//     cout << s.exist(board, "SEE") << endl;
//     cout << s.exist(board, "ABCB") << endl;
// }