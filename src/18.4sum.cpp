#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return kSum(nums, target, 4);
    }

    vector<vector<int>> kSum(vector<int> &nums, int target, int k) {
        sort(nums.begin(), nums.end());

        return helper(nums, nums.size(), target, k);
    }

    vector<vector<int>> helper(vector<int> &nums, int length, int target, int k) {
        vector<vector<int>> res;

        if (length < k) {
            return res;
        }

        if (k == 2) {
            res = twoSum(nums, target, length);
        } else {
            for (int i = length - 1; i >= k - 1; ) {
                vector<vector<int>> t = helper(nums, i, target - nums[i], k - 1);
                for (auto &v : t) {
                    v.push_back(nums[i]);
                    res.push_back(v);
                }
                int a = nums[i];
                do {
                    --i;
                } while (nums[i] == a && i >= k - 1);
            }
        }

        return res;

    }

    vector<vector<int>> twoSum(vector<int> &nums, int target, int length) {
        int l = 0, r = length - 1;
        vector<vector<int>> res;
        while (l < r) {
            if (nums[l] + nums[r] > target) {
                --r;
            } else if (nums[l] + nums[r] < target) {
                ++l;
            } else {
                vector<int> t;
                t.push_back(nums[l]);
                t.push_back(nums[r]);
                res.push_back(t);
                int a = nums[l], b = nums[r];
                do {
                    ++l;
                } while (l < length && nums[l] == a);

                do {
                    --r;
                } while (r >= 0 && nums[r] == b);
            }
        }
        return res;
    }
};
