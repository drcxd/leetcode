class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int/* value */, int/* count */> count;
        for (int i : nums) {
            ++count[i];
        }

        vector<pair<int/* count */ , int/* value */>> v;
        for (auto it : count) {
            // v.push_back(make_pair<int, int>(it.second, it.first));
            v.push_back({it.second, it.first});
        }

        sort(v.begin(), v.end(), [](pair<int, int> &lhs, pair<int, int> &rhs) -> bool {
                                     return lhs.first > rhs.first;
                                 });

        vector<int> res;
        for (int i = 0; i < v.size() && res.size() < k; ++i) {
            res.push_back(v[i].second);
        }
        return res;
    }
private:
};