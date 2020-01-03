class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        // sort(people.begin(), people.end(), [](vector<int> &lhs, vector<int> &rhs)->bool {
        //                                        if (lhs[0] == rhs[0]) {
        //                                            return lhs[1] < rhs[1];
        //                                        }
        //                                        return lhs[0] > rhs[0];
        //                                    });
        // vector<vector<int>> result;
        // for (auto &person : people) {
        //     result.insert(result.begin() + person[1], person);
        // }
        // return result;

        int n = people.size();
        vector<vector<int>> res(n, vector<int>());
        bit = vector<int>(n + 1, 0);
        for (int i = 2; i < n + 1; ++i) {
            update(i, 1);
        }

        sort(people.begin(), people.end(), [](vector<int> &lhs, vector<int> &rhs)->bool {
                                               if (lhs[0] == rhs[0]) {
                                                   return lhs[1] > rhs[1];
                                               }
                                               return lhs[0] < rhs[0];
                                           });

        for (int i = 0; i < n; ++i) {
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (sum(mid + 1) < people[i][1]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            res[l] = people[i];
            update(l + 1, -1);
        }
        return res;
    }
private:

    vector<int> bit; // binary indexed tree, or Fenwick tree

    void update(int i, int v) {
        while (i < bit.size()) {
            bit[i] += v;
            i += (i & -i);
        }
    }

    int sum(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
};