class Solution {
public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        vector<string> let;
        vector<string> dig;
        for (const string &s : logs) {
            size_t pos = s.find(" ");
            if ('0' <= s[pos + 1] && s[pos + 1] <= '9') {
                dig.push_back(s);
            } else {
                let.push_back(s);
            }
        }

        sort(let.begin(), let.end(), [](string &lhs, string &rhs) -> bool {
                                         // same category
                                         int i, j;
                                         for (i = 0; i < lhs.size(); ++i) {
                                             if (lhs[i] == ' ') {
                                                 break;
                                             }
                                         }
                                         for (j = 0; j < rhs.size(); ++j) {
                                             if (rhs[j] == ' ') {
                                                 break;
                                             }
                                         }
                                         string ls(lhs.begin() + i + 1, lhs.end());
                                         string rs(rhs.begin() + j + 1, rhs.end());
                                         int res = lhs.compare(i + 1, lhs.size() - i - 1,
                                                               rhs, j + 1, rhs.size() - j - 1);
                                         if (res == 0) {
                                             return lhs.compare(0, i, rhs, 0, j);
                                         }
                                         return res < 0;
                                       });
        let.insert(let.end(), dig.begin(), dig.end());
        return let;
    }

private:
};