#include <iostream>
using namespace std;

class Solution {
    public:
        double myPow(double x, int n) {
            long long N = n;
            if (N < 0) {
                x = 1 / x;
                N = -N;
            }
            return fastPow(x, N);
        }
    
    private:
        double fastPow(double x, long long n) {
            if (n == 0) return 1.0;
            double half = fastPow(x, n / 2);
            if (n % 2 == 0)
                return half * half;
            else
                return half * half * x;
        }
    };

int main() {

    Solution sol;
    cout << sol.myPow(2.00000, 10) << endl;
    cout << sol.myPow(2.10000, 3) << endl;
    cout << sol.myPow(2.00000, -2) << endl;

    return 0;
}