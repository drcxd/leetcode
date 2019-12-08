class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban;
        for (auto &s : banned) {
            ban.insert(s);
        }

        unordered_map<string, int> count;
        string word;
        int i = 0;
        while (i != paragraph.size()) {
            word = getNextWord(paragraph, &i);
            if (ban.find(word) == ban.end()) {
                ++count[word];
            }
        }

        int max = 0;
        for (auto it : count) {
            if (it.second > max) {
                word = it.first;
                max = it.second;
            }
        }

        return word;
    }
private:

    string getNextWord(const string &paragraph, int *i) {
        string word;
        int j;
        for (j = *i; j < paragraph.size(); ++j) {
            char c = paragraph[j];
            if (isAlpha(c)) {
                word.push_back(c >= 'A' && c <= 'Z' ? ('a' + c - 'A') : c);
            } else {
                break;
            }
        }

        while (j < paragraph.size() && !isAlpha(paragraph[j])) {
            ++j;
        }
        *i = j;
        return word;
    }

    bool isAlpha(char c) {
        return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z';
    }
};