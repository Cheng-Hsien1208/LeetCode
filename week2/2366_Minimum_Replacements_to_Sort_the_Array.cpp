#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long operations = 0; // Store the total number of operations
        int prev = nums[n - 1]; // Initialize with the last element as the reference

        // Traverse from right to left
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > prev) {
                // Calculate the number of splits required
                int k = (nums[i] + prev - 1) / prev; // Equivalent to ceil(nums[i] / prev)
                operations += (k - 1); // Each split adds (k - 1) operations
                prev = nums[i] / k; // Update prev to ensure future numbers remain in non-decreasing order
            } else {
                prev = nums[i]; // No modification needed, update prev
            }
        }
        return operations;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {3, 9, 3};
    vector<int> nums2 = {1, 2, 3, 4, 5};

    cout << sol.minimumReplacement(nums1) << endl; // Output: 2
    cout << sol.minimumReplacement(nums2) << endl; // Output: 0

    return 0;
}
