#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        // Custom comparator for the priority queue (min-heap)
        struct Compare {
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val; // min-heap: smallest value at top
            }
        };
    
        ListNode* mergeKLists(vector<ListNode*>& lists) {priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
    
            // Push the head node of each list into the min-heap
            for (ListNode* list : lists) {
                if (list != nullptr) {
                    minHeap.push(list);
                }
            }
    
            // Dummy node to start the merged list
            ListNode dummy(0);
            ListNode* tail = &dummy;
    
            // Merge the lists using the min-heap
            while (!minHeap.empty()) {
                ListNode* smallest = minHeap.top();
                minHeap.pop();
    
                // Add the smallest node to the result list
                tail->next = smallest;
                tail = tail->next;
    
                // If there's a next node, push it into the heap
                if (smallest->next != nullptr) {
                    minHeap.push(smallest->next);
                }
            }
    
            return dummy.next;
        }
    };

// Helper function to create linked list from vector
ListNode* createList(const vector<int>& nums) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int num : nums) {
        tail->next = new ListNode(num);
        tail = tail->next;
    }
    return dummy.next;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main test
int main() {
    Solution solution;

    // Create test input: [[1,4,5],[1,3,4],[2,6]]
    vector<ListNode*> lists;
    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));

    // Merge and print result
    ListNode* result = solution.mergeKLists(lists);
    cout << "Merged List: ";
    printList(result);

    // Cleanup: delete all nodes
    while (result) {
        ListNode* tmp = result;
        result = result->next;
        delete tmp;
    }

    return 0;
}