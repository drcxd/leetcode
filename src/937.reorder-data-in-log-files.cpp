class Solution {
public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        vector<string> let;
        vector<string> dig;
        for (const string &s : logs) {
            size_t pos = s.find(" ");
            if ('0' <= s[pos + 1] && s[pos + 1] <= '9') {
                dig.push_back(s); // if digit the sequence will not change and we store them in a seperate vector
            } else {
                let.push_back(s); // otherwise store the letter log in a vector which is going to be sorted
            }
        }

        sort(let.begin(), let.end(), [](string &lhs, string &rhs) -> bool {
                                         int i, j;
                                         for (i = 0; i < lhs.size(); ++i) {
                                             if (lhs[i] == ' ') {
                                                 break;
                                             }
                                         } // find the position of the content of the log
                                         for (j = 0; j < rhs.size(); ++j) {
                                             if (rhs[j] == ' ') {
                                                 break;
                                             }
                                         } // find the position of the content of the log
                                         int res = lhs.compare(i + 1, lhs.size() - i - 1,
                                                               rhs, j + 1, rhs.size() - j - 1);
                                         if (res == 0) { // if content same, compare identifier
                                             return lhs.compare(0, i, rhs, 0, j);
                                         }
                                         return res < 0;
                                       });
        let.insert(let.end(), dig.begin(), dig.end()); // concatenate digits with strings
        return let;
    }

private:
};