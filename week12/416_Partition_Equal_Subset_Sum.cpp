#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums) total += num;

        // If total sum is odd, can't split evenly
        if (total % 2 != 0) return false;
        int target = total / 2;

        // dp[i] means whether we can form sum i
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: sum 0 is always possible

        for (int num : nums) {
            // Traverse from target to num (avoid reuse)
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[target];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};
    bool result = sol.canPartition(nums);
    cout << (result ? "true" : "false") << endl; // Output: true
    nums = {1, 2, 3, 5};
    result = sol.canPartition(nums);
    cout << (result ? "true" : "false") << endl; // Output: false
    return 0;
}