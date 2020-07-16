/* *
 * You are given two non-empty linked lists representing two non-negative integers. The digits
 * are stored in reverse order and each of their nodes contain a single digit. Add the two numbers
 * and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ans, *curr;
    int carry = 0, new;
    ans = l1;
    while (1) {
        if (l1 == NULL && l2 == NULL) {
            if (carry == 1) {
                struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));
                n->val = 1;
                n->next = NULL;
                curr->next = n;
                return ans;
            } else
                return ans;
        } else if (l1 == NULL) {
            struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));
            n->val = 0;
            n->next = NULL;
            curr->next = n;
            l1 = n;
        } else if (l2 == NULL) {
            struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));
            n->val = 0;
            n->next = NULL;
            l2 = n;
        }
        new = l1->val + l2->val + carry;
        carry = new / 10;
        new = new % 10;
        curr = l1;
        curr->val = new;
        l1 = l1->next;
        l2 = l2->next;
    }
}
