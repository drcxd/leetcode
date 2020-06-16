class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        unordered_map<char, int> m;
        for (char c : tasks) {
            ++m[c];
        }
        int validIndex[26] = { 0 };
        int taskCount = tasks.size();

        string s;
        while (taskCount > 0) {
            char c = getMax(m);
            --m[c];
            bool put = false;
            for (int i = validIndex[c - 'A']; i < s.size(); ++i) {
                if (s[i] == 0 && i >= validIndex[c - 'A']) {
                    s[i] = c;
                    put = true;
                    break;
                } else if (s[i] == c) {
                    validIndex[c - 'A'] = i + n + 1;
                }
            }
            if (!put) {
                while (s.size() < validIndex[c - 'A']) {
                    s.push_back(0);
                }
                s.push_back(c);
                validIndex[c - 'A'] = s.size() - 1 + n + 1;
            }
            --taskCount;
        }

        int cnt = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == 0) {
                ++cnt;
            } else {
                break;
            }
        }
        return s.size() - cnt;
    }
private:

    char getMax(unordered_map<char, int> &m) {
        int k = 0;
        int v = 0;
        for (auto &it : m) {
            if (it.second > v) {
                v = it.second;
                k = it.first;
            }
        }
        return k;
    }

    int getCount(unordered_map<char, int> &m) {
        int c = 0;
        for (auto &it : m) {
            c += it.second;
        }
        return c;
    }
};