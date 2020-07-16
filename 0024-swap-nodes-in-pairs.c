/**
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 */

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next) return head;
    struct ListNode *newhead, *curr, *temp;
    newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newhead->next = head;
    curr = newhead;
    while (curr->next && curr->next->next) {
        temp = curr->next;
        curr->next = temp->next;
        curr = curr->next;
        temp->next = curr->next;
        curr->next = temp;
        curr = temp;
    }
    return newhead->next;
}
