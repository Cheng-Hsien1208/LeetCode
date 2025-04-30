#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Helper function: generate all next states
    vector<string> getNextStates(const string& state) {
        vector<string> nextStates;
        for (int i = 0; i < 4; i++) {
            string up = state;
            string down = state;
            // turn wheel up
            up[i] = (state[i] == '9') ? '0' : state[i] + 1;
            // turn wheel down
            down[i] = (state[i] == '0') ? '9' : state[i] - 1;
            nextStates.push_back(up);
            nextStates.push_back(down);
        }
        return nextStates;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        queue<string> q;
        int steps = 0;

        if (dead.count("0000")) return -1;

        q.push("0000");
        visited.insert("0000");

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();

                if (cur == target) return steps;

                for (string next : getNextStates(cur)) {
                    if (!dead.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<string> deadends1 = {"0201","0101","0102","1212","2002"};
    string target1 = "0202";
    cout << "Output: " << sol.openLock(deadends1, target1) << endl;

    vector<string> deadends2 = {"8888"};
    string target2 = "0009";
    cout << "Output: " << sol.openLock(deadends2, target2) << endl;

    vector<string> deadends3 = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    string target3 = "8888";
    cout << "Output: " << sol.openLock(deadends3, target3) << endl;

    return 0;
}
