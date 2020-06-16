class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int n = nums.size();
        int less = 0, more = 0;
        int l = -1, r = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                l = i;
                break;
            }
        }

        if (l == -1) {
            return 0;
        }

        for (int i = n - 1; i >= 1; --i) {
            if (nums[i] < nums[i - 1]) {
                r = i;
                break;
            }
        }

        less = nums[l];
        more = nums[r];

        for (int i = l; i <= r; ++i) {
            less = min(less, nums[i]);
            more = max(more, nums[i]);
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] > less) {
                l = i;
                break;
            }
        }

        for(int i = n - 1; i >= 0; --i) {
            if (nums[i] < more) {
                r = i;
                break;
            }
        }

        return r - l + 1;
    }
private:
};