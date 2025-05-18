#include <iostream>
#include <set>
using namespace std;

class ExamRoom {
private:
    int N;
    set<int> seats;

public:
    ExamRoom(int n) {
        N = n;
    }

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }

        int maxDist = *seats.begin(); // distance to seat 0
        int seatToSit = 0;
        int prev = -1;

        for (int s : seats) {
            if (prev != -1) {
                int dist = (s - prev) / 2;
                int mid = prev + dist;
                if (dist > maxDist) {
                    maxDist = dist;
                    seatToSit = mid;
                }
            }
            prev = s;
        }

        // check distance to last seat
        if ((N - 1 - *seats.rbegin()) > maxDist) {
            seatToSit = N - 1;
        }

        seats.insert(seatToSit);
        return seatToSit;
    }

    void leave(int p) {
        seats.erase(p);
    }
};

int main() {
    ExamRoom examRoom(10);
    cout << examRoom.seat() << endl; // Output: 0
    cout << examRoom.seat() << endl; // Output: 9
    cout << examRoom.seat() << endl; // Output: 4
    cout << examRoom.seat() << endl; // Output: 2
    examRoom.leave(4);
    cout << examRoom.seat() << endl; // Output: 5
    return 0;
}