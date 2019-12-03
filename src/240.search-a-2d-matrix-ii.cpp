#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // bool searchMatrix(vector<vector<int>> &matrix, int target) {
    //     if (matrix.size() == 0) {
    //         return false;
    //     }
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     return search(matrix, 0, 0, m - 1, n - 1, target);
    // }
private:

    bool search(vector<vector<int>> &matrix, int li, int lj,
                int ri, int rj, int target) {
        if (li > ri || lj > rj) {
            return false;
        }
        if (li >= matrix.size() || lj >= matrix[0].size() || ri < 0 || rj < 0) {
            return false;
        }
        if (li == ri && lj == rj) {
            return target == matrix[li][lj];
        }
        int mi = (li + ri) / 2;
        int mj = (lj + rj) / 2;
        if (matrix[mi][mj] == target) {
            return true;
        }
        if (target < matrix[mi][mj]) {
            return search(matrix, li, lj, mi - 1, rj, target) ||
                search(matrix, mi, lj, ri, mj - 1, target);
        }
        return search(matrix, li, mj + 1, ri, rj, target) ||
            search(matrix, mi + 1, lj, ri, mj, target);
    }
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (!m) {
            return false;
        }
        int n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0 && matrix[i][j] != target) {
            if (target > matrix[i][j]) {
                ++i;
            } else {
                --j;
            }
        }
        return i < m && j >= 0;
    }
};

// int main() {
//     Solution s;
//     vector<vector<int>> matrix = {
//         {1,   4,  7, 11, 15},
//         {2,   5,  8, 12, 19},
//         {3,   6,  9, 16, 22},
//         {10, 13, 14, 17, 24},
//         {18, 21, 23, 26, 30},
//     };
//     for (int i = 0; i < matrix.size(); ++i) {
//         for (int j = 0; j < matrix[i].size(); ++j) {
//             if (!s.searchMatrix(matrix, matrix[i][j])) {
//                 cout << "error on value " << matrix[i][j] << endl;
//             }
//         }
//     }
//     return 0;
// }