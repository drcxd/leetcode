class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> count;
        for (auto &s : words) {
            ++count[s];
        }

        vector<pair<int, string>> v;
        for (auto it : count) {
            v.push_back(make_pair(it.second, it.first));
        }

        sort(v.begin(), v.end(), [](pair<int, string> &lhs, pair<int, string> &rhs) -> bool {
                                     if (lhs.first == rhs.first) {
                                         return lhs.second < rhs.second;
                                     }
                                     return lhs.first > rhs.first;
                                 });
        vector<string> res;
        for (int i = 0; i < v.size() && res.size() < k; ++i) {
            res.push_back(v[i].second);
        }
        return res;
    }
private:
};