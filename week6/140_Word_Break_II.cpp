#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
    public:
        // wordBreak is the main function that calls dfs to get all valid sentences.
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> wordSet(wordDict.begin(), wordDict.end()); // use set for O(1) lookup
            unordered_map<int, vector<string>> memo; // memoization to cache results
            return dfs(s, 0, wordSet, memo);
        }

        // dfs explores all valid word combinations starting at index 'start'
        vector<string> dfs(const string& s, int start, unordered_set<string>& wordSet, unordered_map<int, vector<string>>& memo) {
            if (memo.count(start)) return memo[start]; // return cached result
            vector<string> result;

            if (start == s.length()) {
                result.push_back(""); // base case: return empty string
                return result;
            }

            for (int end = start + 1; end <= s.length(); ++end) {
                string word = s.substr(start, end - start); // current substring
                if (wordSet.count(word)) { // if substring is in dictionary
                    vector<string> sublist = dfs(s, end, wordSet, memo); // recurse on remaining string
                    for (const string& sub : sublist) {
                        result.push_back(word + (sub.empty() ? "" : " " + sub)); // combine with recursion result
                    }
                }
            }

            memo[start] = result; // store result in memo
            return result;
        }
    };


// Example usage
int main() {
    Solution sol;
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> result = sol.wordBreak(s, wordDict);
    
    for (const string& sentence : result) {
        cout << sentence << endl;
    }
    
    return 0;
}
    