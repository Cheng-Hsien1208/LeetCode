#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window; // store nums[i] as long long to avoid overflow

        for (int i = 0; i < nums.size(); ++i) {
            // Find the smallest number >= nums[i] - valueDiff
            auto it = window.lower_bound((long long)nums[i] - valueDiff);
            
            // Check if this number is within nums[i] + valueDiff
            if (it != window.end() && *it <= (long long)nums[i] + valueDiff) {
                return true;
            }

            // Insert current number into window
            window.insert(nums[i]);

            // Maintain the window size
            if (i >= indexDiff) {
                window.erase(nums[i - indexDiff]);
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3,1};
    cout << sol.containsNearbyAlmostDuplicate(nums1, 3, 0) << endl; // Output: 1 (true)

    vector<int> nums2 = {1,5,9,1,5,9};
    cout << sol.containsNearbyAlmostDuplicate(nums2, 2, 3) << endl; // Output: 0 (false)
}
