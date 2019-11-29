class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        int curr = 0;
        int prev = 0;
        int two_prev = 0;
        for (int i = 0; i < n; ++i) {
            curr = max(prev, two_prev + nums[i]);
            two_prev = prev;
            prev = curr;
        }
        return curr;
    }
};