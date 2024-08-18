#include "LinkedList.h"
int lengthOfCycle(struct ListNode* head) {
    ListNode* turtle = head;
    ListNode* hare = head;
    while (hare && hare->next) {
        hare = hare->next->next;
        turtle = turtle->next;
        if (turtle == hare) {
            ListNode* temp = turtle->next;
            int length = 1;
            while (temp != turtle) {
                temp = temp->next;
                length++;
            }
            return length;
        }
    }
    return 0;
}
ListNode* detectCycle (ListNode* head) {
    int x = 0;
    x = lengthOfCycle(head);
    if (x == 0) return NULL;
    ListNode* h = head;
    ListNode* t = head;
    while (x--) t = t->next;
    while (t != h) {
        t = t->next;
        h = h->next;
    }
    return h;
}