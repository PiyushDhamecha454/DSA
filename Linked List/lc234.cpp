//Palindrome Linked List
#include "LinkedList.h"
ListNode* recRev (ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *newHead = recRev(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* secondHalf = recRev(slow);
    ListNode* firstHalf = head;
    ListNode* secondHalfCopy = secondHalf;
    while (secondHalf) {
        if (firstHalf->val != secondHalf->val) return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    recRev(secondHalfCopy);
    return true;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(1);
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    cout << isPalindrome(node1) << endl;
}