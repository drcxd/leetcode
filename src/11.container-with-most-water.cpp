#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (47.02%)
 * Total Accepted:    460.8K
 * Total Submissions: 980K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 *
 *
 *
 *
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49.
 *
 *
 *
 * Example:
 *
 *
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 *
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int volume = 0;
        int li = 0; // left index
        int ri = height.size() - 1; // right index
        int pl = 0; // previous larger
        int ps = 0; // previous smaller
        int cl = 0; // current larger
        int cs = 0; // current smaller
        while (li < ri) {
            cl = height[li] > height[ri] ? height[li] : height[ri];
            cs = height[li] < height[ri] ? height[li] : height[ri];
            if (cs <= ps) {
                if (cs == height[li]) {
                    ++li;
                } else {
                    --ri;
                }
                continue;
            }
            volume = (ri - li) * cs;
            if (volume > max) {
                max = volume;
            }
            if (cs == height[li]) {
                ++li;
            } else {
                --ri;
            }
            ps = cs;
            pl = cl;
        }
        return max;
        // for (int i = 0; i < height.size() - 1; ++i) {
        //     for (int j = i + 1; j < height.size(); ++j) {
        //         volume = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
        //         if (volume > max) {
        //             max = volume;
        //         }
        //     }
        // }
        // return max;
    }
};

// int main() {
//     vector<int> input = {1,8,6,2,5,4,8,3,7};
//     Solution s;
//     cout << s.maxArea(input) << endl;
//     return 0;
// }