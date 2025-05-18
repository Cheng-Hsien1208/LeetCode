#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canFinish(piles, h, mid)) {
                right = mid;  // Try a smaller speed
            } else {
                left = mid + 1;  // Need a faster speed
            }
        }

        return left;
    }

private:
    // Check if Koko can finish all bananas with speed k within h hours
    bool canFinish(const vector<int>& piles, int h, int k) {
        int totalTime = 0;
        for (int p : piles) {
            totalTime += (p + k - 1) / k;  // Equivalent to ceil(p / k)
        }
        return totalTime <= h;
    }
};

int main() {
    Solution s;
    vector<int> piles1 = {3, 6, 7, 11};
    cout << s.minEatingSpeed(piles1, 8) << endl; // Output: 4

    vector<int> piles2 = {30, 11, 23, 4, 20};
    cout << s.minEatingSpeed(piles2, 5) << endl; // Output: 30

    vector<int> piles3 = {30, 11, 23, 4, 20};
    cout << s.minEatingSpeed(piles3, 6) << endl; // Output: 23
}
