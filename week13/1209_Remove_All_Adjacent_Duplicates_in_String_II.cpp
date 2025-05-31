#include <iostream>
#include <string>
#include <stack>
using namespace std;

string removeDuplicates(string s, int k) {
    // Stack 儲存 pair<char, count>
    stack<pair<char, int>> stk;

    for (char c : s) {
        if (!stk.empty() && stk.top().first == c) {
            stk.top().second++; // Increase count
            if (stk.top().second == k) {
                stk.pop(); // Remove if count == k
            }
        } else {
            stk.push({c, 1}); // New character
        }
    }

    // Build result string
    string result;
    while (!stk.empty()) {
        auto [ch, count] = stk.top();
        stk.pop();
        result.insert(result.begin(), count, ch); // prepend ch*count
    }
    return result;
}

int main() {
    cout << removeDuplicates("abcd", 2) << endl;           // abcd
    cout << removeDuplicates("deeedbbcccbdaa", 3) << endl; // aa
    cout << removeDuplicates("pbbcggttciiippooaais", 2) << endl; // ps
    return 0;
}
