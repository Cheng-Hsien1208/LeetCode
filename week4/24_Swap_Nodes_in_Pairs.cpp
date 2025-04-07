#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node that points to head
        ListNode dummy(0);
        dummy.next = head;

        // prev is a pointer to the node before the current pair
        ListNode* prev = &dummy;

        // Iterate while there are at least two more nodes to swap
        while (prev->next && prev->next->next) {
            // Identify the two nodes to swap
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swap the nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev pointer forward for the next pair
            prev = first;
        }

        // Return the new head
        return dummy.next;
    }
};

// Create a linked list from a vector
ListNode* createList(const vector<int>& vals) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : vals) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

// Print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test case 1: [1, 2, 3, 4]
    vector<int> input1 = {1, 2, 3, 4};
    ListNode* head1 = createList(input1);
    cout << "Input: ";
    printList(head1);
    ListNode* result1 = sol.swapPairs(head1);
    cout << "Output: ";
    printList(result1);

    // Test case 2: []
    vector<int> input2 = {};
    ListNode* head2 = createList(input2);
    cout << "\nInput: ";
    printList(head2);
    ListNode* result2 = sol.swapPairs(head2);
    cout << "Output: ";
    printList(result2);

    // Test case 3: [1]
    vector<int> input3 = {1};
    ListNode* head3 = createList(input3);
    cout << "\nInput: ";
    printList(head3);
    ListNode* result3 = sol.swapPairs(head3);
    cout << "Output: ";
    printList(result3);

    // Test case 4: [1, 2, 3]
    vector<int> input4 = {1, 2, 3};
    ListNode* head4 = createList(input4);
    cout << "\nInput: ";
    printList(head4);
    ListNode* result4 = sol.swapPairs(head4);
    cout << "Output: ";
    printList(result4);

    return 0;
}
