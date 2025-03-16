#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class SlidingWindowMaximum {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // Deque to maintain indices of elements in the window
        
        for (int i = 0; i < nums.size(); i++) {
            // 1. Remove indices that are out of the window range
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // 2. Maintain a decreasing order in the deque, remove smaller elements
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // 3. Insert the current index into the deque
            dq.emplace_back(i);

            // 4. Store the maximum value of the current window when it reaches size k
            if (i >= k - 1) {
                result.emplace_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

// Test case
int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    SlidingWindowMaximum swm;
    vector<int> result = swm.maxSlidingWindow(nums, k);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
