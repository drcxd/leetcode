class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v;
        v.push_back(0);
        if (num > 0) {
            v.push_back(1);
        }
        int pow = 1;
        for (int i = 2; i <= num; ++i) {
            if (i == 1 << pow) {
                ++pow;
            }
            v.push_back(v[i - (1 << (pow - 1))] + 1);
        }
        return v;
    }
private:
};