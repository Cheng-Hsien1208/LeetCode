#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;

        queue<tuple<int, int, int>> q; // (node, visited, steps)
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        // Initialize: Start from every node
        for (int i = 0; i < n; ++i) {
            int mask = (1 << i);
            q.emplace(i, mask, 0);
            visited[i][mask] = true;
        }

        while (!q.empty()) {
            auto [u, mask, steps] = q.front();
            q.pop();

            if (mask == (1 << n) - 1) {
                return steps; // All nodes visited
            }

            for (int v : graph[u]) {
                int nextMask = mask | (1 << v);
                if (!visited[v][nextMask]) {
                    visited[v][nextMask] = true;
                    q.emplace(v, nextMask, steps + 1);
                }
            }
        }

        return -1; // Should not happen
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> graph1 = {{1,2,3},{0},{0},{0}};
    cout << "Shortest Path Length (Example 1): " << sol.shortestPathLength(graph1) << endl;

    // Example 2
    vector<vector<int>> graph2 = {{1},{0,2,4},{1,3,4},{2},{1,2}};
    cout << "Shortest Path Length (Example 2): " << sol.shortestPathLength(graph2) << endl;

    return 0;
}