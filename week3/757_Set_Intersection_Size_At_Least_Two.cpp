#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort intervals by their right endpoint in ascending order.
        // If two intervals have the same right endpoint, sort by left endpoint in descending order.
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] == b[1]) ? (a[0] > b[0]) : (a[1] < b[1]);
        });

        vector<int> nums; // Stores the selected numbers to cover all intervals.
        
        for (auto& interval : intervals) {
            int start = interval[0], end = interval[1];
            int count = 0;
            
            // Count how many numbers in nums are already in the current interval [start, end].
            for (int i = nums.size() - 1; i >= 0 && nums[i] >= start; --i) {
                count++;
            }

            // If less than 2 numbers are present in the interval, add necessary numbers.
            if (count < 2) {
                if (count == 0) {
                    nums.push_back(end - 1);
                    nums.push_back(end);
                } else {
                    nums.push_back(end);
                }
            }
        }
        return nums.size();
    }
};

int main() {
    Solution solution;
    
    vector<vector<int>> intervals1 = {{1,3},{3,7},{8,9}};
    vector<vector<int>> intervals2 = {{1,3},{1,4},{2,5},{3,5}};
    vector<vector<int>> intervals3 = {{1,2},{2,3},{2,4},{4,5}};

    cout << "Test Case 1: " << solution.intersectionSizeTwo(intervals1) << endl; // Expected: 5
    cout << "Test Case 2: " << solution.intersectionSizeTwo(intervals2) << endl; // Expected: 3
    cout << "Test Case 3: " << solution.intersectionSizeTwo(intervals3) << endl; // Expected: 5

    return 0;
}
