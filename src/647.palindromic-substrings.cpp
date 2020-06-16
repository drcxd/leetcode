class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        char dp[n][n] = { 0 };
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
            ++cnt;
        }

        for (int i = 1; i < n; ++i) { // i column, end index
            for (int j = 0; j < i; ++j) { // j row, start index
                if (i - j > 1) {
                    dp[j][i] = dp[j + 1][i - 1] && (s[i] == s[j]);
                } else {
                    dp[j][i] = s[i] == s[j];
                }
                if (dp[j][i]) {
                    ++cnt;
                }
            }
        }

        return cnt;
    }
private:
};