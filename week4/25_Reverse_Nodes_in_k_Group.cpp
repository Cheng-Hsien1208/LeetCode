#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (true) {
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k && kth; ++i) {
                kth = kth->next;
            }
            if (!kth) break;

            ListNode* groupStart = prevGroupEnd->next;
            ListNode* groupEnd = kth;
            ListNode* nextGroupStart = groupEnd->next;

            ListNode* newGroupHead = reverse(groupStart, groupEnd);

            prevGroupEnd->next = newGroupHead;
            groupStart->next = nextGroupStart;

            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }

private:
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* prev = end->next;
        ListNode* curr = start;
        ListNode* next = nullptr;

        while (prev != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return end;
    }
};

// Function to create a linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function for testing
int main() {
    vector<int> vals = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode* head = createList(vals);
    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* result = sol.reverseKGroup(head, k);

    cout << "Reversed in " << k << "-Group: ";
    printList(result);

    return 0;
}
