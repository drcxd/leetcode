#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    int connectSticks(vector<int> &sticks) {
        int cost = 0;
        priority_queue<int, vector<int>, greater<int>> q(sticks.begin(), sticks.end());
        while (q.size() != 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            cost += a + b;
            q.push(a + b);
        }
        return cost;
    }
private:
};
