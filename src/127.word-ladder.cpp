#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        if (wordList.size() == 0) {
            return 0;
        }
        if (wordList.size() == 1) {
            if (wordDiff(wordList[0], beginWord) == 1) {
                return 2;
            } else {
                return 0;
            }
        }
        map<string, vector<string>> adj;
        for (const string &s : wordList) {
            for (const string &i : wordList) {
                if (i != s && wordDiff(s, i) == 1) {
                    adj[s].push_back(i);
                }
            }
        }

        set<vector<string>> paths;
        set<string> visited;

        for (auto it : adj) {
            if (wordDiff(it.first, beginWord) == 1) {
                if (it.first == endWord) {
                    return 2;
                }
                vector<string> path;
                path.push_back(it.first);
                visited.insert(it.first);
                paths.insert(path);
            }
        }

        bool loop = true;
        while (loop) {
            loop = false;
            set<vector<string>> newPaths;
            for (auto itp = paths.begin(); itp != paths.end(); ++itp) {

                for (auto it : adj[itp->back()]) {
                    if (visited.find(it) != visited.end()) {
                        continue;
                    }
                    if (it == endWord) {
                        return itp->size() + 2;
                    }
                    vector<string> newp = *itp;
                    newp.push_back(it);
                    newPaths.insert(newp);
                    visited.insert(it);
                    loop = true;
                }
            }
            paths = newPaths;
        }

        return 0;
    }
private:

    static int wordDiff(const string &l, const string &r) {
        int diff = 0;
        for (int i = 0; i < l.size(); ++i) {
            if (l[i] != r[i]) {
                ++diff;
            }
        }
        return diff;
    }
};

// int main() {
//     Solution s;
//     vector<string> words = {"hot","dot","dog","lot","log","cog"};
//     cout << s.ladderLength("hit", "cog", words) << endl;
//     return 0;
// }