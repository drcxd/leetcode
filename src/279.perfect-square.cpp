#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int numSquares(int n) {

        vector<int> r(n + 1, 0);

        r[1] = 1;

        for (int i = 2; i <= n; ++i) {

            if (sqrt(i) == (int)sqrt(i)) {
                r[i] = 1;
                continue;
            }

            int cur = INT_MAX;

            for (int j = 1; j * j <= i; ++j) {
                cur = min(cur, r[i - j * j] + 1);
            }

            r[i] = cur;
        }
        return r[n];
    }
private:
};

int main() {
    Solution s;
    cout << s.numSquares(12) << endl;
}