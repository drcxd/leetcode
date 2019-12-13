#include <vector>
#include <iostream>
using namespace std;

/**
 * We use a set to store which element we have visited. Then we
 * traverse the grid, if an element is land and it has not been
 * visited, then we have a new island. We visited every element
 * adjacent to it, if it is a '1' then it has been visited and
 * recursively visit the adjacent elements of the element we have just
 * visited.
 */
class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        vector<vector<bool> > visited;
        int num = 0;
        for (auto &v : grid) {
            visited.push_back(vector<bool>(v.size(), false));
        }
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] != '1') {
                    continue;
                }
                if (visited[i][j]) {
                    continue;
                }
                ++num;
                visited[i][j] = true;
                visit_adjacent(i, j, visited, grid);
            }

        }
        return num;
    }

private:

    void visit_adjacent(int i, int j, vector<vector<bool> > &visited, vector<vector<char> > &grid) {
        if (i - 1 >= 0) {
            if (grid[i - 1][j] == '1' && !visited[i - 1][j]) {
                visited[i - 1][j] = true;
                visit_adjacent(i - 1, j, visited, grid);
            }
        }
        if (j - 1 >= 0) {
            if (grid[i][j - 1] == '1' && !visited[i][j - 1]) {
                visited[i][j - 1] = true;
                visit_adjacent(i, j - 1, visited, grid);
            }
        }
        if (i + 1 < grid.size()) {
            if (grid[i + 1][j] == '1' && !visited[i + 1][j]) {
                visited[i + 1][j] = true;
                visit_adjacent(i + 1, j, visited, grid);
            }
        }
        if (j + 1 < grid[i].size()) {
            if (grid[i][j + 1] == '1' && !visited[i][j + 1]) {
                visited[i][j + 1] = true;
                visit_adjacent(i, j + 1, visited, grid);
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<char> > grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };
    cout << s.numIslands(grid) << endl;
    return 0;
}