/**
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or
 * equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the two partitions.
 */

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* partition(struct ListNode* head, int x) {
    if (!head || !head->next) return head;
    struct ListNode* head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *curr1, *curr2;
    curr1 = head1;
    curr2 = head2;
    while (head) {
        if (head->val < x) {
            curr1->next = head;
            curr1 = curr1->next;
        } else {
            curr2->next = head;
            curr2 = curr2->next;
        }
        head = head->next;
    }
    curr2->next = NULL;
    curr1->next = head2->next;
    return head1->next;
}