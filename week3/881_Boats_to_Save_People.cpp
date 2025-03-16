#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());  // Step 1: Sort the array
        int left = 0, right = people.size() - 1;
        int boats = 0;

        while (left <= right) {  // Step 2: Two Pointers approach
            if (people[left] + people[right] <= limit) {
                left++;  // If two people can fit, move left pointer
            }
            right--;  // The heaviest person always gets on a boat
            boats++;  // Always count one boat
        }

        return boats;
    }
};

int main() {
    Solution sol;
    vector<int> people1 = {1,2};
    cout << sol.numRescueBoats(people1, 3) << endl;  // Output: 1

    vector<int> people2 = {3,2,2,1};
    cout << sol.numRescueBoats(people2, 3) << endl;  // Output: 3

    vector<int> people3 = {3,5,3,4};
    cout << sol.numRescueBoats(people3, 5) << endl;  // Output: 4

    return 0;
}
