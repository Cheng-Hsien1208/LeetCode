#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int removeCount = 0;
        int prevEnd = INT_MIN; // initialize to minimum integer

        for (const auto& interval : intervals) {
            if (interval[0] >= prevEnd) {
                // No overlap, update previous end
                prevEnd = interval[1];
            } else {
                // Overlap, need to remove this interval
                removeCount++;
            }
        }
        return removeCount;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};
    int result = sol.eraseOverlapIntervals(intervals);
    cout << "Minimum number of intervals to remove: " << result << endl;
    return 0;
}