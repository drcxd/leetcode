#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int prev = cells[0];
        int temp;

        for (int j = 1; j < 7; ++j) {
            temp = cells[j];
            if (cells[j + 1] == prev) {
                cells[j] = 1;
            } else {
                cells[j] = 0;
            }
            prev = temp;
        }
        cells[0] = 0;
        cells[7] = 0;

        int remain = (N - 1) % 14;
        for (int i = 0; i < remain; ++i) {
            prev = cells[0];
            for (int j = 1; j < 7; ++j) {
                temp = cells[j];
                if (cells[j + 1] == prev) {
                    cells[j] = 1;
                } else {
                    cells[j] = 0;
                }
                prev = temp;
            }
        }

        return cells;
    }
private:
};

// int main() {
//     Solution s;
//     vector<int> cells = { 1, 0, 0, 1, 0, 0, 1, 0 };
//     s.prisonAfterNDays(cells, 1000000000);
//     // vector<int> cells = { 0, 1, 0, 1, 1, 0, 0, 1 };
//     // s.prisonAfterNDays(cells, 7);
//     for (int i : cells) {
//         cout << i << " ";
//     }
//     cout << endl;
//     return 0;
// }