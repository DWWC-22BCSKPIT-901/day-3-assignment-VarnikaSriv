#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        // Handle patterns with '*', as they can match an empty sequence
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1]; 
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; 
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;
    string s1 = "aa";
    string p1 = "a";
    cout << boolalpha << "Input: s = \"" << s1 << "\", p = \"" << p1 << "\"\n";
    cout << "Output: " << sol.isMatch(s1, p1) << "\n\n";
    string s2 = "aa";
    string p2 = "*";
    cout << "Input: s = \"" << s2 << "\", p = \"" << p2 << "\"\n";
    cout << "Output: " << sol.isMatch(s2, p2) << "\n\n";

    string s3 = "cb";
    string p3 = "?a";
    cout << "Input: s = \"" << s3 << "\", p = \"" << p3 << "\"\n";
    cout << "Output: " << sol.isMatch(s3, p3) << "\n\n";

    string s4 = "adceb";
    string p4 = "*a*b";
    cout << "Input: s = \"" << s4 << "\", p = \"" << p4 << "\"\n";
    cout << "Output: " << sol.isMatch(s4, p4) << "\n\n";

    string s5 = "acdcb";
    string p5 = "a*c?b";
    cout << "Input: s = \"" << s5 << "\", p = \"" << p5 << "\"\n";
    cout << "Output: " << sol.isMatch(s5, p5) << "\n";
    return 0;
}
