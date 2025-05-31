#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, 0);  // last occurrence of each letter
        vector<bool> inStack(26, false);  // whether letter is in result

        for (int i = 0; i < s.size(); ++i) {
            last[s[i] - 'a'] = i;
        }

        stack<char> st;

        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];

            if (inStack[ch - 'a']) continue;

            // Pop characters that are greater than current char and appear later
            while (!st.empty() && ch < st.top() && i < last[st.top() - 'a']) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            inStack[ch - 'a'] = true;
        }

        // Construct the result from stack
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    string s = "bcabc";
    string result = sol.removeDuplicateLetters(s);
    cout << result << endl;  // Output: "abc"

    s = "cbacdcbc";
    result = sol.removeDuplicateLetters(s);
    cout << result << endl;  // Output: "acdb"
    return 0;
}
