#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> rotted;
        vector<pair<int, int>> new_rotted;;
        int fresh = 0;
        int m = grid.size();
        if (m == 0) {
            return -1;
        }
        int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    rotted.push_back({i, j});
                } else if (grid[i][j] == 1) {
                    ++fresh;
                }
            }
        }

        int size = 0;
        int count = 0;
        while (fresh > 0 && size != rotted.size()) {
            size = rotted.size();
            for (auto it : rotted) {
                if (it.first - 1 >= 0 && grid[it.first - 1][it.second] == 1) {
                    new_rotted.push_back({it.first - 1, it.second});
                    grid[it.first - 1][it.second] = 2;
                    --fresh;
                }
                if (it.first + 1 < m && grid[it.first + 1][it.second] == 1) {
                    new_rotted.push_back({it.first + 1, it.second});
                    grid[it.first + 1][it.second] = 2;
                    --fresh;
                }
                if (it.second - 1 >= 0 && grid[it.first][it.second - 1] == 1) {
                    new_rotted.push_back({it.first, it.second - 1});
                    grid[it.first][it.second - 1] = 2;
                    --fresh;
                }
                if (it.second + 1 < n && grid[it.first][it.second + 1] == 1) {
                    new_rotted.push_back({it.first, it.second + 1});
                    grid[it.first][it.second + 1] = 2;
                    --fresh;
                }
            }
            rotted.insert(rotted.end(), new_rotted.begin(), new_rotted.end());
            new_rotted.clear();
            ++count;
        };

        if (fresh > 0) {
            return -1;
        }
        return count;
    }
private:
};