#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tree(n);
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        vector<int> res(n, 0), count(n, 1);

        // Post-order DFS
        function<void(int, int)> dfs1 = [&](int node, int parent) {
            for (int child : tree[node]) {
                if (child == parent) continue;
                dfs1(child, node);
                count[node] += count[child];
                res[node] += res[child] + count[child];
            }
        };

        // Pre-order DFS
        function<void(int, int)> dfs2 = [&](int node, int parent) {
            for (int child : tree[node]) {
                if (child == parent) continue;
                res[child] = res[node] - count[child] + (n - count[child]);
                dfs2(child, node);
            }
        };

        dfs1(0, -1);
        dfs2(0, -1);
        return res;
    }
};

int main() {
    Solution sol;
    int n = 6;
    vector<vector<int>> edges = {{0,1}, {0,2}, {2,3}, {2,4}, {2,5}};
    vector<int> result = sol.sumOfDistancesInTree(n, edges);

    cout << "Sum of distances from each node:\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}
