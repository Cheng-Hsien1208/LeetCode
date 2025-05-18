#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>  // for iota

using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0); // Initialize Union-Find structure

        vector<int> candidate1, candidate2;
        unordered_map<int, int> nodeToParent;

        // Step 1: Detect a node with two parents
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (nodeToParent.count(v)) {
                candidate1 = {nodeToParent[v], v}; // First edge to the node
                candidate2 = {u, v};               // Second edge to the node
                edge[1] = 0; // Temporarily disable the second edge
            } else {
                nodeToParent[v] = u;
            }
        }

        // Re-initialize Union-Find roots
        iota(parent.begin(), parent.end(), 0);

        // Step 2: Use Union-Find to detect cycle
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (v == 0) continue; // Skip disabled edge
            int pu = find(parent, u);
            if (pu == v) {
                // Cycle found
                return candidate1.empty() ? edge : candidate1;
            }
            parent[v] = pu;
        }

        // If no cycle and there was a two-parent conflict, return the second edge
        return candidate2;
    }

private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x)
            parent[x] = find(parent, parent[x]); // Path compression
        return parent[x];
    }
};

// === Main function to test ===
int main() {
    Solution sol;

    vector<vector<int>> edges1 = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> result1 = sol.findRedundantDirectedConnection(edges1);
    cout << "Output for edges1: [" << result1[0] << "," << result1[1] << "]" << endl;

    vector<vector<int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}};
    vector<int> result2 = sol.findRedundantDirectedConnection(edges2);
    cout << "Output for edges2: [" << result2[0] << "," << result2[1] << "]" << endl;

    return 0;
}
