class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int res = 0;
        int sum = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i : nums) {
            sum += i;
            if (m.find(sum - k) != m.end()) {
                res += m[sum - k];
            }
            ++m[sum];
        }
        return res;
    }
private:
};