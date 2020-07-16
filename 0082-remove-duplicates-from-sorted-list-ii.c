/**
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the
 * original list.
 */

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head || !head->next) return head;
    struct ListNode* curr = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* fast = head;
    curr->next = head;
    head = curr;
    int cnt = 1;
    while (fast) {
        if (cnt == 1) {
            if (!fast->next || fast->val != fast->next->val) {
                curr->next = fast;
                curr = curr->next;
            } else {
                ++cnt;
            }
        } else if (fast->next && fast->val != fast->next->val) {
            cnt = 1;
        }
        fast = fast->next;
    }
    curr->next = NULL;
    return head->next;
}