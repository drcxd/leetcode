class Solution {
public:
    // quic sort
    // int findKthLargest(vector<int> &nums, int k) {
    //     sort(nums.begin(), nums.end());
    //     return nums[nums.size() - k];
    // }

    int findKthLargest(vector<int> &nums, int k) {
        int curr = nums[k - 1];
        vector<int> bigger;
        vector<int> smaller;

        for (int i = 0; i < nums.size(); ++i) {
            if (i == k - 1) {
                continue;
            }
            if (nums[i] < curr) {
                smaller.push_back(nums[i]);
            } else if (nums[i] >= curr) {
                bigger.push_back(nums[i]);
            }
        }

        if (bigger.size() == k - 1) {
            return curr;
        } else if (bigger.size() < k - 1) {
            return findKthLargest(smaller, k - bigger.size() - 1);
        } else {
            return findKthLargest(bigger, k);
        }
    }

private:
};