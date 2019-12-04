#include <list>
class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        map<int, int> m;

        for (auto &i : intervals) {
            ++m[i.start];
            --m[i.end];
        }

        int res = 0, rooms = 0;
        for (auto &i : m) {
            res += i.second;
            rooms = max(res, rooms);
        }
        return rooms;
    }
private:
};