#include <vector>
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp (n, vector<bool>(n,false));
        for (int i =0;i<n;i++) {
            dp[i][i] = true;
        }
        int ls=0,le =0;
        for (int len =2;len<=n;len++) {
            for (int i=0,j=len-1;j<n;j++,i++) {
                bool ip = (s[i]==s[j]) && (len<=3 || dp[i+1][j-1]);
                if (ip) {ls=i; le= j;}
                dp[i][j] = ip;
            }
        }
        return s.substr(ls,le+1-ls);
    }
};
