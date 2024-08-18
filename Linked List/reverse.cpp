#include "LinkedList.h"
ListNode* recRev (ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *newHead = recRev(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
ListNode* iteRev (ListNode *head) {
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *later = NULL;
    while (curr) {
        later = curr->next;
        curr->next = prev;
        prev = curr;
        curr = later;
    }
    return prev;
}
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    for (int i = 0; i < left - 1; i++) prev = prev->next;
    ListNode* start = prev->next;
    ListNode* then = start->next;
    for (int i = 0; i < right - left; i++) {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
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
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    printList(node1);
    node4 = reverseBetween(node4, 2, 4);
    printList(node1);
}