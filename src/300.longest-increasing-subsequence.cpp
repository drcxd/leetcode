class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (!n) {
            return 0;
        }
        vector<int> l(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    l[i] = max(l[i], l[j] + 1);
                }
            }
        }
        int max = 0;
        for (int i : l) {
            max = i > max ? i : max;
        }
        return max;
    }
private:
};