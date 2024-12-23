#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> substrings;
        int count = 0, start = 0;

        // Split the string into special substrings
        for (int i = 0; i < s.size(); ++i) {
            count += (s[i] == '1') ? 1 : -1;
            if (count == 0) {
                // Recursively process the inner substring
                string inner = makeLargestSpecial(s.substr(start + 1, i - start - 1));
                substrings.push_back("1" + inner + "0");
                start = i + 1;
            }
        }

        // Sort substrings in reverse lexicographical order
        sort(substrings.rbegin(), substrings.rend());

        // Concatenate substrings
        string result = "";
        for (const string& sub : substrings) {
            result += sub;
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "11011000";
    cout << "Input: " << s1 << "\n";
    cout << "Output: " << sol.makeLargestSpecial(s1) << "\n\n";

    // Additional Test Cases
    string s2 = "101100";
    cout << "Input: " << s2 << "\n";
    cout << "Output: " << sol.makeLargestSpecial(s2) << "\n\n";

    string s3 = "111000";
    cout << "Input: " << s3 << "\n";
    cout << "Output: " << sol.makeLargestSpecial(s3) << "\n\n";

    return 0;
}
