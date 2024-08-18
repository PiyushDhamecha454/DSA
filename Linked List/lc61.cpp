#include "LinkedList.h"
ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return NULL;
    ListNode* tail = head;
    int n = 1;
    while (tail->next) {
        tail = tail->next;
        n++;
    }
    tail->next = head;
    k = n - k % n - 1;
    ListNode* newTail = head;
    for (int i = 0; i < k; i++) newTail = newTail->next;
    head = newTail->next;
    newTail->next = NULL;
    return head;
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
    node1 = rotateRight(node1, 3);
    printList(node1);
    return 0;
}