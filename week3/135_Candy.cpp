#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // Initialize each child with at least 1 candy

        // Left to right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1; // Ensure increasing rating gets more candies
            }
        }

        // Right to left pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1); // Ensure decreasing rating gets more candies
            }
        }

        // Calculate the total number of candies
        int total_candies = 0;
        for (int c : candies) {
            total_candies += c;
        }
        return total_candies;
    }
};

int main() {
    Solution solution;
    vector<int> ratings1 = {1, 0, 2};
    vector<int> ratings2 = {1, 2, 2};

    cout << "Output 1: " << solution.candy(ratings1) << endl; // 5
    cout << "Output 2: " << solution.candy(ratings2) << endl; // 4
    return 0;
}
