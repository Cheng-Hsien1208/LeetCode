#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

class FreqStack {
private:
    unordered_map<int, int> freq; // value -> frequency
    unordered_map<int, stack<int>> group; // frequency -> values
    int maxFreq = 0;

public:
    FreqStack() {}

    void push(int val) {
        int f = ++freq[val];
        group[f].push(val);
        if (f > maxFreq) maxFreq = f;
    }

    int pop() {
        int x = group[maxFreq].top(); // get top element in max freq group
        group[maxFreq].pop();         // remove from stack
        freq[x]--;                    // decrease frequency
        if (group[maxFreq].empty()) {
            maxFreq--;               // no more elements at this frequency
        }
        return x;
    }
};

// Example usage
int main() {
    FreqStack fs;
    fs.push(5);
    fs.push(7);
    fs.push(5);
    fs.push(7);
    fs.push(4);
    fs.push(5);
    cout << fs.pop() << endl; // 5
    cout << fs.pop() << endl; // 7
    cout << fs.pop() << endl; // 5
    cout << fs.pop() << endl; // 4
    return 0;
}
