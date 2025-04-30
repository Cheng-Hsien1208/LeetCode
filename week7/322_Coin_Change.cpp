#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Initialize DP array with a large value (amount+1 is effectively infinity)
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // Base case: 0 coins needed to make amount 0

        // Fill the dp array from 1 to amount
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If dp[amount] was not updated, return -1 (not possible to make amount)
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

// Main function for testing
int main() {
    Solution solution;

    // Test case 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Test 1: " << solution.coinChange(coins1, amount1) << endl; // Expected: 3

    // Test case 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Test 2: " << solution.coinChange(coins2, amount2) << endl; // Expected: -1

    // Test case 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Test 3: " << solution.coinChange(coins3, amount3) << endl; // Expected: 0

    // Test case 4
    vector<int> coins4 = {1};
    int amount4 = 2;
    cout << "Test 4: " << solution.coinChange(coins4, amount4) << endl; // Expected: 2

    return 0;
}
