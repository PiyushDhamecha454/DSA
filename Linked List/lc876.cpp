#include "LinkedList.h"
ListNode* middleNode (ListNode* head) {
    ListNode *turtle = head, *hare = head;
    while (hare && hare->next) {
        turtle = turtle->next;
        hare = hare->next->next;
    }
    return turtle;
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
    cout << middleNode(node1)->val << endl;
    ListNode* node6 = new ListNode(6);
    node5->next = node6;
    cout << middleNode(node1)->val << endl;
}