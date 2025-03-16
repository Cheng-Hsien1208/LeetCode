#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> position(n); // Store the current seat index of each person

        // Build the position mapping
        for (int i = 0; i < n; i++) {
            position[row[i]] = i;
        }

        int swaps = 0;

        // Iterate through every pair of seats
        for (int i = 0; i < n; i += 2) {
            int first = row[i];
            int partner = first ^ 1; // Get the expected partner ID

            // If the current seat (row[i+1]) is not the expected partner, swap is needed
            if (row[i + 1] != partner) {
                swaps++;

                // Get the current index of the misplaced partner
                int partnerIndex = position[partner];

                // Swap row[i+1] with row[partnerIndex]
                swap(row[i + 1], row[partnerIndex]);

                // Update the position mapping
                position[row[partnerIndex]] = partnerIndex;
                position[row[i + 1]] = i + 1;
            }
        }
        return swaps;
    }
};

int main() {
    Solution solution;
    vector<int> row1 = {0, 2, 1, 3};
    vector<int> row2 = {3, 2, 0, 1};

    cout << solution.minSwapsCouples(row1) << endl; // Output: 1
    cout << solution.minSwapsCouples(row2) << endl; // Output: 0
    return 0;
}
