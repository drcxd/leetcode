class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> t;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int x = target - nums[i];
            if (t.find(x) != t.end()) {
                res.push_back(t[x]);
                res.push_back(i);
                return res;
            }
            t[nums[i]] = i;
        }
        return res;
    }
private:
};