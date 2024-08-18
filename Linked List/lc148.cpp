#include "LinkedList.h"
ListNode* merge(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}
ListNode* findMiddle(ListNode* head) {
    if (!head) return NULL;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* mid = findMiddle(head);
    ListNode* rightHead = mid->next;
    mid->next = NULL;
    ListNode* left = sortList(head);
    ListNode* right = sortList(rightHead);
    return merge(left, right);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    node4 -> next = node2;
    node2 -> next = node1;
    node1 -> next = node3;
}