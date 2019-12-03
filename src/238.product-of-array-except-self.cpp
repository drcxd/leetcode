class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        int c = 0;
        int pro = 1;
        for (int i : nums) {
            if (i == 0) {
                ++c;
            } else {
                pro *= i;
            }
        }

        vector<int> r;
        if (c > 1) {
            return vector<int>(n, 0);
        } else if (c == 1) {
            for (int i : nums) {
                if (i == 0) {
                    r.push_back(pro);
                } else {
                    r.push_back(0);
                }
            }
        } else {
            r = vector<int>(n, 1);
            for (int i = 1; i < n; ++i) {
                r[i] = r[i - 1] * nums[i - 1];
            }
            int p = 1;
            for (int i = n - 2; i >= 0; --i) {
                p *= nums[i + 1];
                r[i] *= p;
            }
        }
        return r;
    }
private:
};