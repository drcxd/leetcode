#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // int maximalSquare(vector<vector<char>> &matrix) {
    //     int max = 0;
    //     int size = 0;
    //     for (int i = 0; i < matrix.size(); ++i) {
    //         for (int j = 0; j < matrix[i].size(); ++j) {
    //             if (matrix[i][j] == '0') {
    //                 continue;
    //             }
    //             size = 2;
    //             while (checkSquare(i, j, size, matrix)) {
    //                 ++size;
    //             }
    //             if (size - 1 > max) {
    //                 max = size - 1;
    //             }
    //         }
    //     }

    //     return max * max;
    // }

    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int size = 0;
        vector<int> v(matrix[0].size(), 0);
        int northwest = 0, temp;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                temp = v[j];
                if (!i || !j || matrix[i][j] == '0') {
                    v[j] = matrix[i][j] - '0';
                } else {
                    v[j] = min(northwest, min(v[j - 1], v[j])) + 1;
                }
                northwest = temp;
                size = max(size, v[j]);
            }

        }
        return size * size;
    }
private:
    bool checkSquare(int i, int j, int size, vector<vector<char>> &matrix) {
        for (int m = i; m < i + size; ++m) {
            for (int n = j; n < j + size; ++n) {
                if (m >= matrix.size() ||
                    n >= matrix[i].size() ||
                    matrix[m][n] == '0') {
                    return false;
                }
            }
        }
        return true;
    }
};

// int main() {
//     Solution s;
//     vector<vector<char>> matrix = {
//         {'0'},
//     };
//     cout << s.maximalSquare(matrix) << endl;
//     return 0;
// }