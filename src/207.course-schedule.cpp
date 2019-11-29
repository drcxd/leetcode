// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
//         unordered_map<int, vector<int>> m;
//         unordered_set<int> s;
//         for (const auto &v : prerequisites) {
//             m[v[0]].push_back(v[1]);
//         }
//         for (int i = 0; i < numCourses; ++i) {
//             // determine if course i can be finished
//             if (!resolve(i, m, s)) {
//                 return false;
//             }
//         }
//         return true;
//     }
// private:

//     bool resolve(int i, unordered_map<int, vector<int>> &m, unordered_set<int> &s) {
//         if (s.find(i) != s.end()) {
//             return false;
//         }
//         if (m.find(i) == m.end()) {
//             return true;
//         }
//         s.insert(i);
//         for (int x : m[i]) {
//             if (!resolve(x, m, s)) {
//                 return false;
//             }
//         }
//         s.erase(i);
//         return true;
//     }
// };

class Solution {
public:
    bool canFinish(int n, vector<vector<int> > &pre) {
        vector<vector<int> > adj(n, vector<int>()); // pre 2 course
        vector<int> degree(n, 0);
        for (const auto &v : pre) {
            adj[v[1]].push_back(v[0]);
            ++degree[v[0]];
        }
        queue<int> q;
        for (int i = 0; i < degree.size(); ++i) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            --n;
            for (int i : adj[curr]) {
                --degree[i];
                if (degree[i] == 0) {
                    q.push(i);
                }
            }
        }
        return n == 0;
    }
private:
};