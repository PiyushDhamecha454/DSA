#include "LinkedList.h"
ListNode* recRev (ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *newHead = recRev(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
void reorderList(ListNode* head) {
    if (!head || !head->next) return;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* secondHalf = recRev(slow->next);
    slow->next = NULL;
    ListNode* firstHalf = head;
    while (secondHalf) {
        ListNode* temp1 = firstHalf->next;
        ListNode* temp2 = secondHalf->next;
        firstHalf->next = secondHalf;
        secondHalf->next = temp1;
        firstHalf = temp1;
        secondHalf = temp2;
    }
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
    reorderList(node1);
    printList(node1);
}