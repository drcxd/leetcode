class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        if (n == 0 || n == 1) {
            return false;
        }
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum % 2) {
            return false;
        }
        int half = sum / 2;

        sort(nums.begin(), nums.end());
        if (nums[n - 1] > half) {
            return false;
        }

        int req = half - nums[n - 1];
        return hasSum(nums, req, n - 1);
    }
private:

    bool hasSum(const vector<int> &nums, int sum, int sz) {
        if (sum == 0) {
            return true;
        }
        if (sum < 0 || sz == 0) {
            return false;
        }
        for (int i = sz - 1; i >= 0; --i) {
            if (nums[i] > sum) {
                continue;
            }
            if (hasSum(nums, sum - nums[i], i)) {
                return true;
            }
        }
        return false;
    }
};