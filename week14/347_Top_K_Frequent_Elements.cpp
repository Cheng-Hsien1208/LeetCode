#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequency
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create buckets, where index = frequency
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);  // freq can be up to n
        for (auto& [num, count] : freq) {
            bucket[count].push_back(num);
        }

        // Step 3: Collect top-k frequent elements from high to low freq
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; --i) {
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = sol.topKFrequent(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}