#include "LinkedList.h"
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy, *curr = dummy, *next = dummy;
    int n = size(head);
    bool f = false;
    for (int i = 1; i <= n - k + 1; i += k) {
        curr = prev->next;
        next = curr->next;
        for (int j = 1; j < k; j++) {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        prev = curr;
    }
    return dummy->next;
}
ListNode* reverseAltKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy, *curr = dummy, *next = dummy;
    int n = size(head);
    bool f = false;
    while (true) {
        ListNode* start = prev->next;
        curr = prev;
        for (int i = 0; i < k; i++) {
            curr = curr->next;
            if (!curr) return dummy->next;
        }
        if (!f) {
            curr = prev->next;
            next = curr->next;
            for (int j = 1; j < k; j++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
        }
        prev = curr;
        f = !f;
    }
    return dummy->next;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    printList(node1);
    ListNode* result = reverseAltKGroup(node1, 2);
    printList(result);
    return 0;
}