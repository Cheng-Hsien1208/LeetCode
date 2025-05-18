#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            int left = 0, right = n - 1;
            int left_max = 0, right_max = 0;
            int water = 0;
    
            while (left < right) {
                if (height[left] < height[right]) {
                    if (height[left] >= left_max)
                        left_max = height[left];  // update left max
                    else
                        water += left_max - height[left];  // water trapped
                    left++;
                } else {
                    if (height[right] >= right_max)
                        right_max = height[right];  // update right max
                    else
                        water += right_max - height[right];  // water trapped
                    right--;
                }
            }
    
            return water;
        }
    };

int main() {
    Solution s;
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(height1) << endl; // Output: 6

    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << s.trap(height2) << endl; // Output: 9

    return 0;
}