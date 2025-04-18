#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        // Heapify function to maintain max heap property
        void heapify(vector<int>& nums, int n, int i) {
            int largest = i;       // Initialize largest as root
            int left = 2 * i + 1;  // left child index
            int right = 2 * i + 2; // right child index

            // If left child is larger than root
            if (left < n && nums[left] > nums[largest])
                largest = left;

            // If right child is larger than largest so far
            if (right < n && nums[right] > nums[largest])
                largest = right;

            // If largest is not root
            if (largest != i) {
                swap(nums[i], nums[largest]);  // Swap root with largest
                heapify(nums, n, largest);     // Recursively heapify the affected sub-tree
            }
        }

        vector<int> sortArray(vector<int>& nums) {
            int n = nums.size();

            // Build max heap
            for (int i = n / 2 - 1; i >= 0; i--) {
                heapify(nums, n, i);
            }

            // Extract elements from heap one by one
            for (int i = n - 1; i >= 0; i--) {
                swap(nums[0], nums[i]);     // Move current root to end
                heapify(nums, i, 0);        // Heapify reduced heap
            }

            return nums;
        }
    };

int main() {
    Solution solution;
    
    vector<int> nums = {5, 2, 3, 1};

    cout << "Original array: ";
    for (int n : nums)
        cout << n << " ";
    cout << endl;

    vector<int> sorted = solution.sortArray(nums);

    cout << "Sorted array: ";
    for (int n : sorted)
        cout << n << " ";
    cout << endl;

    return 0;
}