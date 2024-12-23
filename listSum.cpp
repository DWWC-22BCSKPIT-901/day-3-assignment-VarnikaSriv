#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); // Dummy node to simplify logic
        ListNode* current = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10; // Calculate carry for the next digit
            current->next = new ListNode(sum % 10); 
            current = current->next;
        }

        return dummyHead->next; // Return the next node as the head of the result
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
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    ListNode* l1 = createList(arr1, n1);
    ListNode* l2 = createList(arr2, n2);

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);
    return 0;
}
