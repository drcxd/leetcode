class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int w = 0, r = 0, c = 0;
        while (r < nums.size()) {
            if (nums[r]) {
                nums[w++] = nums[r];
            }
            ++r;
        }
        for (; w < nums.size(); ++w) {
            nums[w] = 0;
        }
    }
};
