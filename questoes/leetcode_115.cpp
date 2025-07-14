#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int tamS = s.length();
        int tamT = t.length();

        if (tamS < tamT) {
            return 0;
        }

        vector<uint64_t> dp(tamT + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= tamS; ++i) {
            for (int j = tamT; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return (int)dp[tamT];
    }
};