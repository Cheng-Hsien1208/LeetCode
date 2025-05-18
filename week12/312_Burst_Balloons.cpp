#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // Add 1 to both ends
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int size = n + 2;

        vector<vector<int>> dp(size, vector<int>(size, 0));

        // Length of interval
        for (int len = 2; len < size; ++len) {
            for (int left = 0; left < size - len; ++left) {
                int right = left + len;
                for (int k = left + 1; k < right; ++k) {
                    // k is the last balloon to burst between (left, right)
                    dp[left][right] = max(dp[left][right],
                        dp[left][k] + dp[k][right] + nums[left] * nums[k] * nums[right]);
                }
            }
        }

        return dp[0][size - 1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, 5, 8};
    int result = sol.maxCoins(nums);
    cout << result << endl; // Output: 167
    return 0;
}