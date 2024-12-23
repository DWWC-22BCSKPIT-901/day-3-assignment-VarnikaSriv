#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: if head is null or only one node, return it
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* reversedHead = reverseList(head->next);
        // Reverse the current node's link
        head->next->next = head;
        head->next = nullptr;
        return reversedHead;
    }
};
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* tail = head;
    for (int i = 1; i < n; i++) {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    ListNode* head = createList(arr, n);
    cout << "Original List: ";
    printList(head);
    
    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);
    
    cout << "Reversed List: ";
    printList(reversedHead);
    return 0;
}
