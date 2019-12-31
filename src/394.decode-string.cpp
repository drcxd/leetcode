class Solution {

public:

    string decodeString(string s) {
        string r;
        for (int i = 0; i < s.size(); ) {
            if ('0' <= s[i] && s[i] <= '9') {
                string numstr;
                while ('0' <= s[i] && s[i] <= '9') {
                    numstr.push_back(s[i]);
                    ++i;
                }
                int num = stoi(numstr);
                string sub;
                int open = 0;
                ++i;
                for ( ; i < s.size(); ++i) {
                    if (s[i] == '[') {
                        ++open;
                        sub.push_back(s[i]);
                    } else if (s[i] == ']') {
                        if (open == 0) {
                            while (num > 0) {
                                r.append(decodeString(sub));
                                --num;
                            }
                            break;
                        } else {
                            --open;
                            sub.push_back(s[i]);
                        }
                    } else {
                        sub.push_back(s[i]);
                    }
                }
                ++i;
            } else {
                r.push_back(s[i]);
                ++i;
            }
        }

        return r;

    }

private:

};