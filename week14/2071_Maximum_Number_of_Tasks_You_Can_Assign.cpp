#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool check(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> available(workers.end() - k, workers.end()); // take k strongest workers

        for (int i = k - 1; i >= 0; --i) {
            int task = tasks[i];

            // 找最小一個 ≥ task 的 worker（不吃藥）
            auto it = available.lower_bound(task);
            if (it != available.end()) {
                available.erase(it); // 使用這個 worker
            } else {
                // 吃藥也還不夠的就無法完成
                if (pills == 0) return false;

                // 找最小一個 ≥ task - strength 的 worker，給他吃藥
                it = available.lower_bound(task - strength);
                if (it == available.end()) return false;

                available.erase(it);
                pills--;
            }
        }
        return true;
    }

    int maxTasks(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min((int)tasks.size(), (int)workers.size());
        int answer = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(mid, tasks, workers, pills, strength)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
};


// Example usage:
int main() {
    Solution sol;
    vector<int> tasks = {3, 2, 1};
    vector<int> workers = {0, 3, 3};
    int pills = 1;
    int strength = 1;
    int result = sol.maxTasks(tasks, workers, pills, strength);
    cout << "Maximum number of tasks that can be assigned: " << result << endl;
    return 0;
}