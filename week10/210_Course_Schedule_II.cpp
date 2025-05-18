#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // adjacency list for graph
        vector<vector<int>> graph(numCourses);
        // in-degree array
        vector<int> inDegree(numCourses, 0);

        // Build graph and compute in-degree
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            graph[prereq].push_back(course);
            inDegree[course]++;
        }

        // Queue for nodes with zero in-degree
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        // Result list to store topological order
        vector<int> order;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);

            // Reduce in-degree of neighbors
            for (int neighbor : graph[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If not all courses are in order, it means there's a cycle
        if (order.size() != numCourses)
            return {};
        
        return order;
    }
};

int main() {
    Solution sol;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> result = sol.findOrder(numCourses, prerequisites);

    cout << "Course order: ";
    for (int course : result) {
        cout << course << " ";
    }
    cout << endl;

    return 0;
}
