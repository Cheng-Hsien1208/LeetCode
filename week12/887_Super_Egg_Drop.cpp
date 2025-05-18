#include <iostream>
#include <vector>
using namespace std;

int superEggDrop(int k, int n) {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    int m = 0;
    while (dp[k][m] < n) {
        m++;
        for (int i = 1; i <= k; ++i) {
            dp[i][m] = dp[i - 1][m - 1] + dp[i][m - 1] + 1;
        }
    }
    return m;
}

int main() {
    cout << superEggDrop(1, 2) << endl;  // Output: 2
    cout << superEggDrop(2, 6) << endl;  // Output: 3
    cout << superEggDrop(3, 14) << endl; // Output: 4
    return 0;
}
