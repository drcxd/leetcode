class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        sort(points.begin(), points.end(), [](vector<int> &lhs, vector<int> &rhs) -> bool {
                                               return lhs[0] * lhs[0] + lhs[1] * lhs[1] <
                                                   rhs[0] * rhs[0] + rhs[1] * rhs[1];
                                           });
        vector<vector<int>> res;
        for (int i = 0; i < K && i < points.size(); ++i) {
            res.push_back(points[i]);
        }
        return res;
    }
private:
};