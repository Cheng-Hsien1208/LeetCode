#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, cur_end = 0, farthest = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]); // Update the farthest position that can be reached
            
            if (i == cur_end) { // When reaching the end of the current jump range, make a jump
                jumps++;
                cur_end = farthest; // Update the boundary for the next jump
            }
        }
        return jumps;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,3,1,1,4};
    cout << sol.jump(nums) << endl; // Output: 2
    return 0;
}
