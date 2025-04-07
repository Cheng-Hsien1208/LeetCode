#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;   // Store all permutations
        vector<int> path;             // Current permutation
        vector<bool> used(nums.size(), false); // Mark used elements
        backtrack(nums, used, path, result);
        return result;
    }

    void backtrack(const vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& result) {
        if (path.size() == nums.size()) {
            result.push_back(path);  // Found a complete permutation
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;   // Skip if already used

            path.push_back(nums[i]);  // Choose
            used[i] = true;

            backtrack(nums, used, path, result);  // Explore

            path.pop_back();        // Undo choice (Backtrack)
            used[i] = false;
        }
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}