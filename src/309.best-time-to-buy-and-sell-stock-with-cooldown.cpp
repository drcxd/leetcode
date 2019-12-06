class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }

        vector<int> p;
        p.push_back(0);

        for (int i = 1; i < n; ++i) {
            int x = p[i - 1];
            for (int j = i - 1; j >= 0; --j) {
                if (prices[j] >= prices[i]) {
                    break;
                }
                x = max(x, prices[i] - prices[j] + (j - 2 > 0 ? p[j - 2] : 0));
            }
            p.push_back(x);
        }
        return p[n - 1];
    }
private:
};