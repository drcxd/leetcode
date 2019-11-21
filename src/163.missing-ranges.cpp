#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        vector<string> r;
        long long prev = lower;
        for (int i = 0; i < nums.size(); ++i) {
            long long delta = nums[i] - prev;
            if (delta > 1) {
                stringstream ss;
                ss << prev << "->" << nums[i] - 1;
                r.push_back(ss.str());
            } else if (delta == 1) {
                stringstream ss;
                ss << prev;
                r.push_back(ss.str());
            }
            prev = nums[i] + (long long)1;
        }
        if (upper - prev >= 1) {
            stringstream ss;
            ss << prev << "->" << upper;
            r.push_back(ss.str());
        } else if (upper - prev >= 0) {
            stringstream ss;
            ss << upper;
            r.push_back(ss.str());
        }
        return r;
    }
};

int main() {
    Solution s;
    vector<string> r;
    // vector<int> nums = {0, 1, 3, 50, 75};
    // vector<string> r = s.findMissingRanges(nums, 0, 99);
    // vector<int> nums = {0, 1, 2, 3, 7};
    // vector<string> r = s.findMissingRanges(nums, 0, 7);
    // vector<int> nums = { };
    // r = s.findMissingRanges(nums, -2147483648, 2147483647);
    vector<int> nums = { 2147483647 };
    r = s.findMissingRanges(nums, 0, 2147483647);
    for (auto & s : r) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}