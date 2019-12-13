class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) {
            return s;
        }

        int max_len = 0, pos = 0, len, left, right;
        for (int i = 0; i < n; ++i) {
            if (n - i <= max_len / 2) {
                break;
            }
            left = right = i;
            while (right < n  - 1 && s[right] == s[right + 1]) {
                ++right;
            }
            while (left > 0 && right < n - 1) {
                if (s[left - 1] == s[right + 1]) {
                    --left;
                    ++right;
                } else{
                    break;
                }
            }
            len = right - left + 1;
            if (len > max_len) {
                max_len = len;
                pos = left;
            }
        }

        return s.substr(pos, max_len);
    }
private:
};