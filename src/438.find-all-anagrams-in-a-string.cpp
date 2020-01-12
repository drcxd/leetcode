class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int notAnagram = 0, count[26], ls = s.size(), lp = p.size();
        memset(count, 0, 26 * sizeof(int));
        vector<int> res;
        if (lp > ls) {
            return res;
        }

        for (char c : p) {
            update(c, count, notAnagram, 1);
        }

        for (int i = 0; i < ls; ++i) {
            update(s[i], count, notAnagram, -1);

            if (i >= lp) {
                update(s[i - lp], count, notAnagram, 1);
            }

            if (!notAnagram) {
                res.push_back(i - lp + 1);
            }
        }

        return res;
    }
private:

    void update(char c, int *count, int &flag, int amount) {
        int i = c - 'a';
        count[i] += amount;
        flag = count[i] ? flag | (1 << i) : flag & ~(1 << i);
    }
};
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> result;
//         unordered_set<int> dict;
//         if (p.size() > s.size()) {
//             return result;
//         }
//         int sp = 0;
//         while (sp < s.size() - p.size() + 1) {
//             if (dict.find(sp - 1) != dict.end()) {
//                 if (s[sp - 1] == s[sp + p.size() - 1]) {
//                     dict.insert(sp);
//                 }
//                 ++sp;
//                 continue;
//             }
//             int r = isAnagram(s, p, sp);
//             if (r == -1) {
//                 dict.insert(sp);
//                 ++sp;
//             } else if (r == -2) {
//                 ++sp;
//             } else {
//                 sp = r + 1;
//             }
//         }
//         result = vector<int>(dict.begin(), dict.end());
//         return result;
//     }
// private:

//     int count_buffer[26];
//     char show_buffer[26];
//     int isAnagram(const string &str, const string &p, int s) {
//         memset(count_buffer, 0, 26 * sizeof(int));
//         memset(show_buffer, 0, 26 * sizeof(char));
//         for (char c : p) {
//             ++count_buffer[c - 'a'];
//             show_buffer[c - 'a'] = 1;
//         }
//         for (int i = s; i < s + p.size() && i < str.size(); ++i) {
//             if (!show_buffer[str[i] - 'a']) {
//                 return i;
//             }
//             --count_buffer[str[i] - 'a'];
//         }
//         for (int i = 0; i < 26; ++i) {
//             if (count_buffer[i] != 0) {
//                 return -2;
//             }
//         }
//         return -1;
//     }
// };