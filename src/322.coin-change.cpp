#include <algorithm>
#include <unordered_set>

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int c : coins) {
            for (int i = c; i <= amount; ++i) {
                dp[i] = min(dp[i - c] + 1, dp[i]);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};