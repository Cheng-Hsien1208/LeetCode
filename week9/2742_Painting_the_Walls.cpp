#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n + 1, 1e9); // dp[i]: minimum cost to paint i walls
        dp[0] = 0; // 0 walls cost 0

        for (int i = 0; i < n; ++i) {
            for (int j = n; j >= 0; --j) {
                int next = min(n, j + time[i] + 1);
                dp[next] = min(dp[next], dp[j] + cost[i]);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    
    vector<int> cost1 = {1, 2, 3, 2};
    vector<int> time1 = {1, 2, 3, 2};
    cout << sol.paintWalls(cost1, time1) << endl; // Output: 3

    vector<int> cost2 = {2, 3, 4, 2};
    vector<int> time2 = {1, 1, 1, 1};
    cout << sol.paintWalls(cost2, time2) << endl; // Output: 4

    return 0;
}
