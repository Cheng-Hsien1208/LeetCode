#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> stopToBuses;
        int n = routes.size();

        // Step 1: Build stop -> buses map
        for (int i = 0; i < n; ++i) {
            for (int stop : routes[i]) {
                stopToBuses[stop].push_back(i);
            }
        }

        queue<int> q; // current bus stop
        unordered_set<int> visitedStops;
        unordered_set<int> visitedBuses;
        q.push(source);
        visitedStops.insert(source);

        int buses = 0;

        while (!q.empty()) {
            int size = q.size();
            buses++;  // new level means taking one more bus
            while (size--) {
                int currStop = q.front(); q.pop();

                // Check all buses we can take from this stop
                for (int bus : stopToBuses[currStop]) {
                    if (visitedBuses.count(bus)) continue;
                    visitedBuses.insert(bus);

                    for (int nextStop : routes[bus]) {
                        if (nextStop == target)
                            return buses;
                        if (!visitedStops.count(nextStop)) {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> routes1 = {{1,2,7}, {3,6,7}};
    cout << sol.numBusesToDestination(routes1, 1, 6) << endl; // Output: 2

    vector<vector<int>> routes2 = {{7,12}, {4,5,15}, {6}, {15,19}, {9,12,13}};
    cout << sol.numBusesToDestination(routes2, 15, 12) << endl; // Output: -1

    return 0;
}

