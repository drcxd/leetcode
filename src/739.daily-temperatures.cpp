class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T) {
        vector<int> v;
        vector<int> dp;
        if (T.size() == 0) {
            return v;
        }

        int n1 = T[0];
        bool put = false;
        for (int i = 1; i < T.size(); ++i) {
            if (T[i] > n1) {
                v.push_back(i);
                dp.push_back(i);
                put = true;
                break;
            }
        }
        if (!put) {
            v.push_back(0);
            dp.push_back(0);
        }

        for (int i = 1; i < T.size(); ++i) {
            int j = i + 1;
            if (T[i] > T[i - 1]) {
                j = i - 1 + dp[i - 1] + 1;
            } else if (T[i] == T[i - 1]) {
                if (dp[i - 1]) {
                    v.push_back(dp[i - 1] - 1);
                    dp.push_back(dp[i - 1] - 1);
                } else {
                    v.push_back(0);
                    dp.push_back(0);
                }
                continue;
            }
            put = false;
            for ( ; j < T.size(); ++j) {
                if (T[j] > T[i]) {
                    v.push_back(j - i);
                    dp.push_back(j - i);
                    put = true;
                    break;
                }
            }
            if (!put) {
                v.push_back(0);
                dp.push_back(0);
            }
        }

        return v;
    }
private:
};